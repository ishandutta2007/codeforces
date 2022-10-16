#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pii pair <int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define sor(v) sort(all(v))
#define rev(v) reverse(all(v))
#define mem(v,x) memset(v,x,sizeof(v))

const int N=2e5+5;
const int mod=1e9+7;

int ksm(int a,int b){
	int s=1,m=a;
	while(b){
		if(b&1)s=1ll*s*m%mod;
		m=1ll*m*m%mod,b>>=1;
	}
	return s;
}
int inv(int x){return ksm(x,mod-2);}

int n,q,a[N],d[N<<3],pre[N],ans[N];
vector <pii> ed[N];

int c[N];
void add(int x,int v){while(x<=n)c[x]=1ll*c[x]*v%mod,x+=x&-x;}
int query(int x){int ans=1; while(x)ans=1ll*ans*c[x]%mod,x-=x&-x; return ans;}
void upd(int x,int v){if(d[v])add(d[v],1ll*v*inv(v-1)%mod); add(d[v]=x,1ll*(v-1)*inv(v)%mod);}

int main(){
	scanf("%d",&n),pre[0]=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pre[i]=1ll*pre[i-1]*a[i]%mod,c[i]=1;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		ed[r].pb({l,i});
	}
	for(int i=1;i<=n;i++){
		int tmp=a[i];
		for(int j=2;j*j<=tmp;j++)if(tmp%j==0){upd(i,j); while(tmp%j==0)tmp/=j;}
		if(tmp>1)upd(i,tmp);
		for(pii it:ed[i])ans[it.se]=1ll*pre[i]*inv(pre[it.fi-1])%mod*query(i)%mod*inv(query(it.fi-1))%mod;
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	
	return 0;
}