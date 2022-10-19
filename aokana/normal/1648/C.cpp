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
	template<class T>friend modint operator+(modint cnt,T b){return cnt+=b;}
	template<class T>friend modint operator-(modint cnt,T b){return cnt-=b;}
	template<class T>friend modint operator*(modint cnt,T b){return cnt*=b;}
	template<class T>friend modint operator^(modint cnt,T b){return cnt/=b;}
	template<class T>friend modint operator/(modint cnt,T b){return cnt/=b;}
	friend modint operator^(modint cnt,int b){return cnt^=b;}
	friend bool operator==(modint cnt,int b){return cnt.val==b;}
	friend bool operator!=(modint cnt,int b){return cnt.val!=b;}
	inline bool operator!(){return !val;}
	inline modint operator-(){return val?mod-val:0;}
	inline modint &operator++(){return *this+=1;}
};
using mi=modint;
mi ans,fac[maxn],ifac[maxn],mul=1;
inline void init(int sz){
	fac[0]=1;
	for(ri i=1;i<=sz;++i)fac[i]=fac[i-1]*i;
	ifac[sz]=1/fac[sz];
	for(ri i=sz;i;--i)ifac[i-1]=ifac[i]*i;
}
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		T ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		T ret=0;
		for(;r;r^=lowbit(r))ret+=c[r];
		for(--l;l;l^=lowbit(l))ret-=c[l];
		return ret;
	}
};
BIT<mi>t;
int b[maxn],cnt[maxn],m,n;
int main(){
	init(200000);
	scanf("%d%d",&n,&m);
	t.mx_idx=2e5;
	for(ri i=1,x;i<=n;++i){
		scanf("%d",&x);
		++cnt[x];
	}
	for(ri i=1;i<=200000;++i)
		if(cnt[i]){
			t.add(i,cnt[i]);
			mul*=ifac[cnt[i]];
		}
	for(ri i=1;i<=m;++i)scanf("%d",b+i);
	for(ri i=1;i<=min(n,m);++i){
		ans+=fac[n-i]*mul*t.query(b[i]-1);
		mul*=cnt[b[i]];
		t.add(b[i],mod-1);
		if(!cnt[b[i]]--)goto skip;
	}
	if(n<m)++ans;
	skip:;
	printf("%d",ans);
	return 0;
}