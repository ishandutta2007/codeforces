#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int _N=1e6+7,_B=1e9;
char _S[_N];
ll _C[_N*2/9];
struct big{
	vector<int>a;
	bool f;
	big(){a.clear(),f=0;}
	big(const char*s){
		int i=0,l=strlen(s),j;
		if(a.clear(),f=0,s[0]=='-')i=f=1;
		if(s[i]=='0')return;
		j=(l-i-1)%9+1,a.push_back(0);
		for(;i<l;(a.back()*=10)+=s[i++]-48,--j)if(!j)a.push_back(0),j=9;
		reverse(a.begin(),a.end());
	}
	big(const string&s){*this=s.c_str();}
	big(int x){
		a.clear(),x<0?(x=-x,f=1):(f=0);
		if(x)x<_B?(a.push_back(x)):(a.push_back(x%_B),a.push_back(x/_B));
	}
	big(const ll&x){sprintf(_S,"%lld",x),*this=_S;}
	explicit operator int(){
		int l=a.size(),i,r=0;
		for(i=l-1;~i;--i)r=r*_B+a[i];
		return f?-r:r;
	}
	explicit operator ll(){
		int l=a.size(),i;
		ll r=0;
		for(i=l-1;~i;--i)r=r*_B+a[i];
		return f?-r:r;
	}
	explicit operator bool(){return!a.empty();}
	int abscmp(const big&x)const{
		int l=a.size(),o=x.a.size();
		if(l!=o)return l<o?-1:1;
		while(l--)if(a[l]!=x.a[l])return a[l]<x.a[l]?-1:1;
		return 0;
	}
	int cmp(const big&x)const{
		if(a.empty())return x.a.empty()?0:(x.f?1:-1);
		if(x.a.empty())return f?-1:1;
		if(!f&&x.f)return 1;
		if(f&&!x.f)return -1;
		return f?-abscmp(x):abscmp(x);
	}
	friend bool operator<(const big&x,const big&y){return x.cmp(y)<0;}
	friend bool operator>(const big&x,const big&y){return x.cmp(y)>0;}
	friend bool operator<=(const big&x,const big&y){return x.cmp(y)<=0;}
	friend bool operator>=(const big&x,const big&y){return x.cmp(y)>=0;}
	friend bool operator==(const big&x,const big&y){return x.cmp(y)==0;}
	friend bool operator!=(const big&x,const big&y){return x.cmp(y)!=0;}
	big&operator+(){return*this;}
	big operator-(){
		big x=*this;
		return x.f^=1,x;
	}
	void add1(){
		if(++a[0]==_B){
			a.push_back(0);
			for(int i=0;a[i]==_B;++i)a[i]=0,++a[i+1];
			if(!a.back())a.pop_back();
		}
	}
	void sub1(){
		if(--a[0]==-1){
			for(int i=0;a[i]==-1;++i)a[i]+=_B,--a[i+1];
			if(!a.back())a.pop_back();
		}
	}
	big&operator++(){return a.empty()?(a.push_back(1),f=0,void()):(f?sub1():add1()),*this;}
	big&operator--(){return a.empty()?(a.push_back(1),f=1,void()):(f?add1():sub1()),*this;}
	big operator++(int){
		big x=*this;
		return a.empty()?(a.push_back(1),f=0,void()):(f?sub1():add1()),x;
	}
	big operator--(int){
		big x=*this;
		return a.empty()?(a.push_back(1),f=1,void()):(f?add1():sub1()),x;
	}
	void fit(){while(!a.empty()&&!a.back())a.pop_back();}
	void add(const big&x){
		int i,l=a.size(),o=x.a.size(),j;
		if(l<o)a.resize(o);
		a.push_back(0);
		for(i=0;i<o;++i){
			j=a[i]+x.a[i];
			if(j>=_B)j-=_B,++a[i+1];
			a[i]=j;
		}
		fit();
	}
	void sub(const big&x){
		int i,l=a.size(),o=x.a.size(),j;
		for(i=0;i<o;++i){
			j=a[i]-x.a[i];
			if(j<0)j+=_B,--a[i+1];
			a[i]=j;
		}
		for(i=o;i<l;++i)if(a[i]<0)a[i]+=_B,--a[i+1];
		fit();
	}
	void mul(const big&x){
		int i,l=a.size(),o=x.a.size(),j,k;
		ll w;
		for(memset(_C,0,(k=l+o)*8),i=0;i<o;++i)for(j=0;j<l;++j)
		w=x.a[i]*1ll*a[j]+_C[i+j],_C[i+j]=w%_B,_C[i+j+1]+=w/_B;
		for(a.resize(k),i=0;i<k;++i)a[i]=_C[i];
		fit();
	}
	int div(const int&x){
		int i,l=a.size();
		ll w=0;
		for(i=l-1;~i;--i)w=w*_B+a[i],a[i]=w/x,w-=a[i]*1ll*x;
		return fit(),w;
	}
	big div(const big&x){
		int i,l=a.size(),o=x.a.size(),j=l-o;
		ll u,v,w;
		big r;
		if(j<0)return r=*this,*this=0,r;
		for(i=l-1;i>j;--i)r=r*_B+a[i];
		for(i=j,a.resize(j+1);~i;--i){
			r=r*_B+a[i],u=0,v=_B-1;
			while(u<=v){
				w=u+v>>1;
				if(x*w<=r)u=w+1;else v=w-1;
			}
			a[i]=u-1,r-=x*a[i];
		}
		return fit(),r;
	}
	big&operator+=(const big&x){
		if(f==x.f)add(x);
		else if(abscmp(x)>=0)sub(x);
		else{
			big y=x;
			y.sub(*this),*this=y;
		}
		return*this;
	}
	big&operator-=(const big&x){
		if(f!=x.f)add(x);
		else if(abscmp(x)>=0)sub(x);
		else{
			big y=x;
			y.sub(*this),*this=y,f^=1;
		}
		return*this;
	}
	big&operator*=(const big&x){return mul(x),f=(f==x.f?0:1),*this;}
	big&operator/=(const int&x){return div(abs(x)),f=(((f&&x<0)||(!f&&x>0))?0:1),*this;}
	big&operator/=(const big&x){return div(x),f=(f==x.f?0:1),*this;}
	big&operator/=(const ll&x){return*this/=(big)x;}
	big&operator%=(const int&x){return*this=f?-div(abs(x)):div(abs(x));}
	big&operator%=(const big&x){return*this=f?-div(x):div(x);}
	big&operator%=(const ll&x){return*this%=(big)x;}
	friend big operator+(big x,const big&y){return x+=y,x;}
	friend big operator-(big x,const big&y){return x-=y,x;}
	friend big operator*(big x,const big&y){return x*=y,x;}
	friend big operator/(big x,const ll&y){return x/=y,x;}
	friend big operator/(big x,const int&y){return x/=y,x;}
	friend big operator/(big x,const big&y){return x/=y,x;}
	friend ll operator%(big x,const ll&y){return x%=y,(ll)x;}
	friend int operator%(big x,const int&y){return x%=y,(int)x;}
	friend big operator%(big x,const big&y){return x%=y,x;}
};
void in(big&x){scanf("%s",_S),x=_S;}
void out(const big&x){
	int i=x.a.size();
	if(!i)return putchar('0'),void();
	if(x.f)putchar('-');
	for(printf("%d",x.a[--i]);i--;)printf("%09d",x.a[i]);
}
void out(const big&x,const char&c){out(x),putchar(c);}
void swap(big&x,big&y){swap(x.f,y.f),swap(x.a,y.a);}
big abs(big x){return x.f=0,x;}
big qp(big a,int b){
	big r=1;
	for(;b;b>>=1){
		if(b&1)r*=a;
		if(b)a*=a;
	}
	return r;
}
big gcd(big a,big b){
	big r=1;
	while(1){
		if(!a||!b)return(a+b)*r;
		while(a.a[0]%2==0&&b.a[0]%2==0)r*=2,a/=2,b/=2;
		while(a.a[0]%2==0)a/=2;
		while(b.a[0]%2==0)b/=2;
		if(a<b)swap(a,b);
		a-=b;
	}
}
const int N=3e5+3,P=1e9+7;
int a[N],b[N],c[N],f[N],s[N];
int main(){
	int n,i,j,k,l=0;
	big m;
	cin>>n;
	for(a[1]=1,i=2;i<=n;++i)cin>>a[i];
	for(i=1;i<=n;++i)cin>>b[i];
	in(m);
	for(i=2;i<=n;++i){
		if(m==0){n=i-1;break;}
		if(a[i]>1){
			big t=m/a[i];
			c[i]=int(m-t*a[i]),m=t;
		}
	}
	f[0]=1;
	for(i=1;i<=n;++i){
		k=-1;
		for(j=c[i];j<=l;j+=a[i])f[k=j/a[i]]=f[j];
		l=l/a[i]+b[i];
		for(j=0;j<=k;++j)s[j+1]=(s[j]+f[j])%P;
		for(;j<=l;++j)s[j+1]=s[j];
		for(j=0;j<=l;++j)f[j]=(s[j+1]-s[max(0,j-b[i])])%P;
	}
	if(m>l)cout<<0;else cout<<(f[(int)m]+P)%P;
	return 0;
}