#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10,mod=998244353;
struct modint{
	int val;
	inline modint(int val_=0):val(val_){}
	inline modint &operator=(int val_){return val=val_,*this;}
	inline modint &operator+=(const modint &k){return val=val+k.val>=mod?val+k.val-mod:val+k.val,*this;}
	inline modint &operator-=(const modint &k){return val=val-k.val<0?val-k.val+mod:val-k.val,*this;}
	inline modint &operator*=(const modint &k){return val=1ll*val*k.val%mod,*this;}
	inline modint &operator^=(int k){
	    modint ret=1,tmp=*this;
	    for(;k;k>>=1,tmp*=tmp)if(k&1)ret*=tmp;
	    return val=ret.val,*this;
	}
	inline modint &operator/=(modint k){return *this*=(k^=mod-2);}
	inline modint &operator+=(int k){return val=val+k>=mod?val+k-mod:val+k,*this;}
	inline modint &operator-=(int k){return val=val<k?val-k+mod:val-k,*this;}
	inline modint &operator*=(int k){return val=1ll*val*k%mod,*this;}
	inline modint &operator/=(int k){return *this*=((modint(k))^=mod-2);}
	template<class T>friend modint operator+(modint a,T b){return a+=b;}
	template<class T>friend modint operator-(modint a,T b){return a-=b;}
	template<class T>friend modint operator*(modint a,T b){return a*=b;}
	template<class T>friend modint operator^(modint a,T b){return a/=b;}
	template<class T>friend modint operator/(modint a,T b){return a/=b;}
	friend modint operator^(modint a,int b){return a^=b;}
	friend bool operator==(modint a,int b){return a.val==b;}
	friend bool operator!=(modint a,int b){return a.val!=b;}
	inline bool operator!(){return !val;}
	inline modint operator-(){return val?mod-val:0;}
	inline modint &operator++(){return *this+=1;}
};
using mi=modint;
mi fac[maxn],ifac[maxn],pw2[maxn];
inline void init(int sz){
	fac[0]=pw2[0]=1;
	for(ri i=1;i<=sz;++i)fac[i]=fac[i-1]*i,pw2[i]=pw2[i-1]+pw2[i-1];
	ifac[sz]=1/fac[sz];
	for(ri i=sz;i;--i)ifac[i-1]=ifac[i]*i;
}
inline mi C(int x,int y){
	if(x<y||y<0)return 0;
	return fac[x]*ifac[y]*ifac[x-y];
}
inline mi f(int x,int y){
	mi sum=0;
	for(ri i=0;i<=min(x,y);++i)sum+=C(x+1,i+1)*C(y+1,i+1);
	return sum;
}
int a[maxn],m,n,t_case;
inline mi calc(int l,int r){
	if(l>=r)return 1;
	ll lsum=0,rsum=a[r];
	mi ret=1;
	for(ri i=l,j=r;i<r;++i){
		lsum+=a[i];
		while(j-1>i&&(lsum>rsum+a[j-1]||(a[j-1]&&lsum==rsum+a[j-1])))rsum+=a[--j];
		if(j<=i)break;
		if(lsum==rsum){
			if(all_of(a+i+1,a+j,[&](int x){return !x;}))ret=pw2[j-i];
			else{
				ri L=0,R=0;
				for(ri k=i+1;k<j&&!a[k];++k,++L);
				for(ri k=j-1;k>i&&!a[k];--k,++R);
				ret+=calc(i+L+1,j-R-1)*(f(L,R)+1)-1;
			}
			break;
		}
	}
	return ret;
}
int main(){
	init(200000);
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		printf("%d\n",calc(1,n));
	}
	return 0;
}