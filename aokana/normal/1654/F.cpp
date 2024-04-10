#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef unsigned long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=18,bs1=2333,bs2=2337,mod=1e9+7;
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
struct hsh{
	mi x,y;
	inline hsh(mi x_=0,mi y_=0):x(x_),y(y_){}
	inline hsh operator+(const hsh &k)const{return hsh(x+k.x,y+k.y);}
	inline hsh operator*(const hsh &k)const{return hsh(x*k.x,y*k.y);}
	inline bool operator==(const hsh &k)const{return x.val==k.x.val&&y.val==k.y.val;}
}bs[1<<maxn],f[1<<maxn][maxn+1];
int ans,m,n;
char s[1<<maxn|1];
int main(){
	scanf("%d%s",&n,s);
	bs[0]=hsh(1,1),f[0][0]=hsh(s[0],s[0]);
	for(ri i=1;i<1<<n;++i)bs[i]=bs[i-1]*hsh(bs1,bs2),f[i][0]=hsh(s[i],s[i]);
	for(ri i=1;i<=n;++i)
		for(ri j=0;j<1<<n;++j)
			f[j][i]=f[j][i-1]+bs[1<<i-1]*f[j^1<<i-1][i-1];
	auto check=[&](int x,int y){
		if(f[x][n]==f[y][n])return true;
		for(ri i=n;i;--i)
			if(f[x][i-1]==f[y][i-1])
				x^=1<<i-1,y^=1<<i-1;
		return s[x]<s[y];
	};
	for(ri i=1;i<1<<n;++i)
		if(check(i,ans))
			ans=i;
	for(ri i=0;i<1<<n;++i)putchar(s[i^ans]);
	return 0;
}