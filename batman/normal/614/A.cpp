#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define int64 long long
using namespace std;
const int bignumlen=2200; //mishe taghir dad
const int Blen=8; 
const int64 base=100000000; 
struct bignum{
    int len;
    int64 data[bignumlen];
    int64 &operator [](int x){ return(data[x]);}
    const int64 &operator [](int x)const { return(data[x]);}
    bignum (){
        memset(data,0,sizeof(data));
        len=0;
    }
    void clear(){
        for(int i=len;i>=1;--i)data[i]=0;
        len=0;
    }
    int check (const bignum &a,const bignum &b){
        if(a.len>b.len)return(0);
        if(b.len>a.len)return(1);
        for(int i=a.len;i>=1;--i){
            if(a.data[i]<b.data[i])return(1);
            if(b.data[i]<a.data[i])return(0);
        }
        return 2;
    }
    bool operator < (const bignum &b){ return(check(*this,b)==1);}
    bool operator > (const bignum &b){ return(check(*this,b)==0);}
    bool operator <=(const bignum &b){ return(check(*this,b)>=1);}
    bool operator >=(const bignum &b){ return(check(*this,b)%2==0);}
    bool operator !=(const bignum &b){ return(check(*this,b)!=2);}
    bool operator ==(const bignum &b){ return(check(*this,b)==2);}
    
    bignum operator=(const bignum &x){
        for(int i=x.len+1;i<=len;++i)data[i]=0;
        for(int i=1;i<=x.len;++i)data[i]=x.data[i];
        len=x.len;
        return *this;
    }
    bignum operator=(int64 x){
        for(int i=len;i>=0;--i)data[i]=0;
        len=0;
        while(x){
            data[++len]=x%base;
            x/=base;
        }
        return *this;
    }
    bignum(int64 x){
        memset(data,0,sizeof(data));
        len=0;
        (*this)=x;
    }
    bignum operator *(const bignum &b){
        int i,j;
        bignum tmp;
        for(i=1;i<=len;++i)if(data[i]!=0)
            for(j=1;j<=b.len;++j)if(b.data[j]!=0){
                tmp.data[i+j-1]+=data[i]*b.data[j];
                tmp.data[i+j]+=tmp.data[i+j-1]/base;
                tmp.data[i+j-1]%=base;
            }
        tmp.len=len+b.len-1;
        while(tmp.data[tmp.len+1])tmp.len++;
        return tmp;
    }
    bignum operator *(int64 x){
        int i;
        bignum tmp;
        for(i=1;i<=len;++i)tmp[i]=data[i]*x;
        tmp.len=len;
        for(i=1;i<=len;++i){
            tmp[i+1]+=tmp[i]/base,tmp[i]%=base;
            if(tmp[i+1]&&i+1>tmp.len)tmp.len++;
        }
        return tmp;
    }
    bignum operator /(int64 x){
        int i;
        bignum tmp;
        int64 y=0;
        for(i=len;i>=1;--i){
            y=y*base+data[i];
            tmp[i]=y/x;
            y%=x;
        }
        tmp.len=len;
        while(tmp[tmp.len]==0&&tmp.len>1)tmp.len--;
        return tmp;
    }
    bignum operator /(const bignum &b){
        if(b.len<=1 && b[1]==0){
            printf("error! ?0?!");
            for(;;);
        }
        int i,l1=(len-1)*Blen,l2=(b.len-1)*Blen;
        int64 x=data[len],y=b[b.len];
        while(x)x/=10,l1++;
        while(y)y/=10,l2++;
        bignum tmp,chu,B;
        chu=*this; B=b;
        
        for(i=1;i*Blen<=l1-l2;++i)B*=base;
        for(i=1;i<=(l1-l2)%Blen;++i)B*=10;
        for(i=l1-l2;i>=0;--i){
            x=0;
            while(chu>=B)chu-=B,x++;
            tmp[i/Blen+1]=tmp[i/Blen+1]*10+x;
            B/=10;
        }
        tmp.len=(l1-l2)/Blen+1;
        while(tmp.len>=1 && !tmp[tmp.len])tmp.len--;
        return tmp;
    }
    bignum operator +(const bignum &b){
        bignum tmp;
        int i,l=max(len,b.len);
        for(i=1;i<=l;++i)tmp[i]=data[i]+b[i];
        for(i=1;i<=l;++i)tmp[i+1]+=tmp[i]/base,tmp[i]%=base;
        tmp.len=l;
        if(tmp[tmp.len+1])tmp.len++;
        return tmp;
    }
    bignum operator +(int64 x){
        bignum tmp; tmp=*this;
        tmp[1]+=x;
        for(int i=1;i<=len&&tmp[i]>=base;++i)tmp[i+1]+=tmp[i]/base,tmp[i]%=base;
        while(tmp[tmp.len+1])tmp.len++;
        return tmp;
    }
    bignum operator -(const bignum &b){
        int i;
        bignum tmp;
        for(i=1;i<=len;++i)tmp.data[i]=data[i]-b.data[i];
        for(i=1;i<=len;++i){
            if(tmp[i]<0)tmp.data[i]+=base,tmp.data[i+1]--;
        }
        tmp.len=len;
        while(tmp[tmp.len]==0&&tmp.len>1)tmp.len--;
        return tmp;
    }
    bignum operator -(int64 x){
        bignum tmp; tmp=*this;
        tmp[1]-=x;
        for(int i=1;i<=len&&tmp[i]<0;++i){
            tmp[i+1]+=(tmp[i]+1)/base-1;
            tmp[i]=(tmp[i]+1)%base+base-1;
        }
        while(!tmp[tmp.len]&&tmp.len>1)tmp.len--;
        return tmp;
    }
    int64 operator %(int64 x){
        int i;
        int64 y=0;
        for(i=len;i>=1;--i)y=(y*base+data[i])%x;
        return y;
    }
    bignum operator %(const bignum &b){
        if(b.len<=1 && b[1]==0){
            printf("error! ?0 mod!");
            for(;;);
        }
        int i,l1=(len-1)*Blen,l2=(b.len-1)*Blen;
        int64 x=data[len],y=b[b.len];
        while(x)x/=10,l1++;
        while(y)y/=10,l2++;
        bignum chu,B;
        chu=*this; B=b;
        
        for(i=1;i*Blen<=l1-l2;++i)B*=base;
        for(i=1;i<=(l1-l2)%Blen;++i)B*=10;
        for(i=l1-l2;i>=0;--i){
            while(chu>=B)chu-=B;
            B/=10;
        }
        return chu;
    }
    
    bignum operator +=(const bignum &b){return *this=(*this+b);}
    bignum operator *=(const bignum &b){return *this=(*this*b);}
    bignum operator -=(const bignum &b){return *this=(*this -b);}
    bignum operator /=(const bignum &b){return *this=(*this/b);}
    bignum operator %=(const bignum &b){return *this=(*this%b);}
    bignum operator *=(int64 x) {return( *this=(*this *x));}
    bignum operator +=(int64 x) {return( *this=(*this +x));}
    bignum operator -=(int64 x) {return( *this=(*this -x));}
    bignum operator /=(int64 x) {return( *this=(*this /x));}
    void read(){
        char c[bignumlen*Blen+10];
        scanf("%s",c+1);
        int l=strlen(c+1);
        (*this).clear();
        int64 x;
        for(int i=1;i<=(l-1)/Blen+1;++i){
            x=0;
            for(int j=l-Blen*i+1;j<=l-Blen*i+Blen;++j)if(j>=1)x=x*10+c[j]-48;
            data[++len]=x;
        }
    }
    void write(){
        printf("%I64d",data[len]);
        for(int i=len-1;i>=1;--i)printf("%0*I64d",Blen,data[i]);
        printf(" ");
    }
};
bignum gcd(const bignum &A,const bignum &B){
    bignum a=A,b=B,res=1;
    while(!(a[1]&1)  && !(b[1]&1))a/=2,b/=2,res*=2;
    for(;;){
        if(a.len==1 && a[1]==0)return b*res;
        if(b.len==1 && b[1]==0)return a*res;
        while(!(a[1]&1))a/=2;
        while(!(b[1]&1))b/=2;
        if(a>b)a-=b;
        else b-=a;
    }
}
void YF(bignum &A,bignum &B){
    bignum tmp=gcd(A,B);
    A/=tmp; B/=tmp;
}

int main(){
	long long l,r,k,p=0;
	scanf("%I64d %I64d %I64d",&l,&r,&k);
	bignum tmp=1;
	while(tmp<=(bignum)r)
	{
		if((bignum)l<=tmp)
			p++,tmp.write();
		tmp*=k;	
	}
	if(!p)printf("-1");
}