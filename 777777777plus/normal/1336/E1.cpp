#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
const int M = 35;
const int mod = 998244353;

int n,m;
int cnt0;
ll a[N];
ll wB[N];
ll wA[19][N];
ll ans[N];

ll qpow(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)r=r*a%mod;
		b>>=1;a=a*a%mod;
	}
	return r;
}

ll popcount(ll x){
	int r=0;
	for(int i=0;i<m;++i)
	if(x&1ll<<i){
		r++;
	}
	return r;
}

struct Basis{
	ll a[M];
	
	bool insert(ll x){
		for(int i=m-1;~i;--i)
		if(x&1ll<<i){
			x^=a[i];
		}
		for(int i=m-1;~i;--i)
		if((x&1ll<<i)&&!a[i]){
			a[i]=x;
			for(int j=m-1;j>i;--j)
			if(a[j]&1ll<<i){
				a[j]^=x;
			}
			return 1;
		}
		return 0;
	}
	
}T;

void dfs(vector<ll> A,int x,ll w,bool type){
	if(x==A.size()){
		if(!type){
			++wB[w];
		}
		else{
			int cnt=popcount(w^(w&((1ll<<m/2)-1)));
			++wA[cnt][w&((1ll<<m/2)-1)];
		}
		return;
	}
	dfs(A,x+1,w,type);
	dfs(A,x+1,w^A[x],type);
}

struct FWT{
	int n;
	
	void prepare(int len){
		for(n=1;n<=len;n<<=1);
	}

	void fwt(ll *a,int f){
		ll rev=1;
		if(f==-1)rev=qpow(2,mod-2);
		for(int i=1;i<n;i<<=1){
			for(int j=0;j<n;j+=i<<1){
				for(int k=0;k<i;++k){
					ll x=a[j+k],y=a[j+k+i];
					a[j+k]=(x+y)*rev%mod;a[j+k+i]=(x-y+mod)*rev%mod;
	//				xor a[j+k]=x+y;a[j+k+i]=x-y;
	//					a[j+k]=(x+y)/2;a[j+k+i]=(x-y)/2;
	//				and	a[j+k]=x+y;
	//					a[j+k]=x-y;
	//				or	a[j+k+i]=x+y;
	//					a[j+k+i]=y-x;
				}
			}
		}
	}
}F;


int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)
	if(!T.insert(a[i])){
		cnt0++;
	}
	vector<ll> A,B;
	for(int i=0;i<m/2;++i)if(T.a[i])B.push_back(T.a[i]);
	for(int i=m/2;i<m;++i)if(T.a[i])A.push_back(T.a[i]);
	dfs(B,0,0,0);
	dfs(A,0,0,1);
	F.prepare((1ll<<17)-1);
	F.fwt(wB,1);
	for(int i=0;i<=18;++i){
		F.fwt(wA[i],1);
		for(int j=0;j<F.n;++j)wA[i][j]=wA[i][j]*wB[j]%mod;
		F.fwt(wA[i],-1);
		for(int j=0;j<F.n;++j){
			int cnt=popcount(j);
			(ans[cnt+i]+=wA[i][j])%=mod;
		}
	}
	for(int i=0;i<=m;++i){
		ans[i]=ans[i]*qpow(2,cnt0)%mod;
		printf("%lld ",ans[i]); 
	} 
}