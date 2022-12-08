#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
const ll mod = 998244353;

int n,m,k;
ll b2[N];
int a[N][2],b[N][2],tot,ca[3],cb[3],c[2];
map<pair<int,int>,int> vis;

void delet(int x,int y){
	if(vis.find({x,y})==vis.end())return;
	int v=vis[{x,y}];
	vis.erase({x,y});
	--tot;
	c[(x+y&1)^v]--;
	int x1=(x&1)^v,y1=(y&1)^v;
	if((--a[y][x1])==0){
		if(a[y][x1^1])--ca[0],++ca[1];
		else --ca[1],++ca[2];
	}
	if((--b[x][y1])==0){
		if(b[x][y1^1])--cb[0],++cb[1];
		else --cb[1],++cb[2];
	}
}

void insert(int x,int y,int v){
	vis[{x,y}]=v;
	++tot;
	c[(x+y&1)^v]++;
	int x1=(x&1)^v,y1=(y&1)^v;
	if((a[y][x1]++)==0){
		if(a[y][x1^1])--ca[1],++ca[0];
		else --ca[2],++ca[1];
	}
	if((b[x][y1]++)==0){
		if(b[x][y1^1])--cb[1],++cb[0];
		else --cb[2],++cb[1];
	}
}

int main(){
	b2[0]=1;
	for(int i=1;i<N;++i)b2[i]=b2[i-1]*2%mod;
	cin>>n>>m>>k;
	ca[2]=m;
	cb[2]=n;
	for(int i=1,x,y,t;i<=k;++i){
		scanf("%d%d%d",&x,&y,&t);
		if(t==-1){
			delet(x,y);
		}
		else{
			delet(x,y);
			insert(x,y,t);
		}
		ll ans=0;
		if(!tot){
			ans=(b2[n]+b2[m]-2+mod)%mod;
		}
		else{
			if(!c[0]||!c[1])ans=(ans-1+mod)%mod;
			if(!ca[0]){
				ans=(ans+b2[ca[2]])%mod;
			}
			if(!cb[0]){
				ans=(ans+b2[cb[2]])%mod;
			}
		}
		printf("%lld\n",ans);
	}
}