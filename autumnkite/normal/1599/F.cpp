#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=1e9+7;
const int inv2=(mod+1)/2;
typedef long long ll;
int n,Q,a[N],ans[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
const int inv6=qpow(6,mod-2);
class BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	void Add(int x,int d){
		while(x)b[x]=(b[x]+d)%mod,x-=lowbit(x);	
	}
	int Ask(int x){
		int ans=0;
		while(x<=n)ans=(ans+b[x])%mod,x+=lowbit(x);
		return ans;
	}
}B[4];
vector<tuple<int,int,int> > q[N];
map<int,int> las;
void Change(int u,int w){
	for(int i=0,t=1;i<=3;++i,t=1LL*t*a[u]%mod){
		B[i].Add(u,w==1?t:mod-t);
	}	
}
inline int S1(int x){
	return 1LL*x*(x+1)%mod*inv2%mod;	
}
inline int S2(int x){
	return 1LL*x*(x+1)%mod*(2*x+1)%mod*inv6%mod;
}
inline int S3(int x){
	return 1LL*S1(x)*S1(x)%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	for(int i=1;i<=Q;++i){
		int l,r,d;
		cin>>l>>r>>d;
		q[r].emplace_back(l,d,i);
	}
	for(int i=1;i<=n;++i){
		if(las.count(a[i])){
			Change(las[a[i]],-1);
		}
		Change(i,1);
		las[a[i]]=i;
		for(auto [L,_d,id]:q[i]){
			int num[4]={};
			int d=qpow(_d,mod-2);
			for(int i=0,t=1;i<=3;++i,t=1LL*t*d%mod){
				num[i]=1LL*B[i].Ask(L)*t%mod;	
			}
			int len=num[0];
			int jb=2LL*qpow(len,mod-2)*num[1]%mod;
			int l=(1LL*inv2*(jb+1-len)%mod+mod)%mod;
			int r=(l+len-1)%mod;
			if((S2(r)-S2((l+mod-1)%mod)+mod)%mod==num[2] &&
				(S3(r)-S3((l+mod-1)%mod)+mod)%mod==num[3]){
				ans[id]=1;
			}
		}
	}
	for(int i=1;i<=Q;++i){
		cout<<(ans[i]?"Yes\n":"No\n");	
	}
	return 0;
}