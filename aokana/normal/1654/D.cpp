#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=4e5+10,mod=998244353;
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
int fac[maxn];
vector<int>pri;
inline void sieve(int siz){
	fac[1]=1;
	for(ri i=2;i<=siz;++i){
		if(!fac[i])fac[i]=i,pri.push_back(i);
		for(ri j:pri){
			if(i*j>siz)break;
			fac[i*j]=j;
			if(i%j==0)break;
		}
	}
}
int cnt[maxn],mx[maxn];
struct node{int to,x,y;};
vector<node>e[maxn];
void dfs(int p,int f){
	for(const node &i:e[p])
		if(i.to!=f){
			ri x=i.x,y=i.y;
			while(y!=1){
				ri k=fac[y];
				do ++cnt[k],y/=k;while(y%k==0);
			}
			while(x!=1){
				ri k=fac[x];
				do --cnt[k],x/=k;while(x%k==0);
				ckmax(mx[k],-cnt[k]);
			}
			dfs(i.to,p);
			x=i.x,y=i.y;
			while(y!=1){
				ri k=fac[y];
				do --cnt[k],y/=k;while(y%k==0);
			}
			while(x!=1){
				ri k=fac[x];
				do ++cnt[k],x/=k;while(x%k==0);
			}
		}
}
mi sum;
void dfs_(int p,int f,mi cur){
//	printf("! %d %d\n",p,cur);
	sum+=cur;
	for(const node &i:e[p])
		if(i.to!=f)
			dfs_(i.to,p,cur*i.y/i.x);
}
int n,t_case;
int main(){
	sieve(200000);
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		clear(cnt,n),clear(mx,n);
		for(ri i=1;i<=n;++i)vector<node>().swap(e[i]);
		for(ri i=1,x,y,xx,yy;i<n;++i){
			scanf("%d%d%d%d",&x,&y,&xx,&yy);
			e[x].push_back({y,xx,yy});
			e[y].push_back({x,yy,xx});
		}
		dfs(1,0);
		mi mul=1;
		for(ri i=1;i<=n;++i)mul*=mi(i)^mx[i];
		sum=0;
		dfs_(1,0,mul);
		printf("%d\n",sum);
	}
	return 0;
}