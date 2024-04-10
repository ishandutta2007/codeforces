#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m,head[101000],cnt,res;
ll dis[101000];
vector<ll>v;
struct lb{//linear basis?
	ll d[64];
	int tot;
	void print(){
		for(int i=0;i<=62;i++)if(d[i])printf("%d:%lld\n",i,d[i]);
	}
	void clear(){memset(d,0,sizeof(d)),tot=0;}
	lb(){memset(d,0,sizeof(d)),tot=0;}
	void operator +=(ll x){
		for(int i=62;i>=0;i--){
			if(!(x&(1ll<<i)))continue;
			if(d[i])x^=d[i];
			else{d[i]=x,tot++;break;}
		}
	}
	ll& operator [](int x){
		return d[x];
	}
	void operator +=(lb &x){
		for(int i=62;i>=0;i--)if(x[i])*this+=x[i];
	}
	friend lb operator +(lb &x,lb &y){
		lb z=x;
		for(int i=62;i>=0;i--)if(y[i])z+=y[i];
		return z;
	}
	int calc(){//calculate the number of possible xor values, from the vector v
//		for(ll i:v)printf("%lld ",i);puts("");
//		printf("TTT:%d\n",tot);
//		print();
		ll tmp=0;
		int ret=0,sz=v.size();
		for(int i=62;i>=0;i--)if(d[i])tmp|=d[i];
		for(int i=62;i>=0;i--){
			int cnt=0;
			for(ll j:v)cnt+=((j>>i)&1);
			if(tmp&(1ll<<i))(ret+=((1ll<<i)%mod)*((1ll<<(tot-1))%mod)%mod*((1ll*sz*(sz-1)/2)%mod)%mod)%=mod;
			else(ret+=((1ll<<i)%mod)*((1ll<<tot)%mod)%mod*(1ll*cnt*(sz-cnt)%mod)%mod)%=mod;
		}
		return ret;
	}
}LB;
struct node{
	int to,next;
	ll val;
}edge[400100];
void ae(int u,int v,ll w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++; 
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++; 
}
bool vis[100100];
void dfs(int x){
	vis[x]=true,v.push_back(dis[x]);
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(!vis[edge[i].to])dis[edge[i].to]=dis[x]^edge[i].val,dfs(edge[i].to);
		else LB+=dis[x]^dis[edge[i].to]^edge[i].val;
	}
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(ll i=1,x,y,z;i<=m;i++)scanf("%lld%lld%lld",&x,&y,&z),ae(x,y,z);
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i),(res+=LB.calc())%=mod,LB.clear(),v.clear();
	printf("%d\n",res);
	return 0;
}
/*
5 4
1 3 234
5 1 432
4 2 624
3 5 754
*/