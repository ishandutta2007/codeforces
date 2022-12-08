#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
const ll mod = 998244353;

int T;
int n,m,k;
int x[N],y[N],xx[N],yy[N];
int vx[N],vy[N];
map<int,int> cntx[N],cnty[N];

struct BIT{
	int a[N];
	void add(int x,int d){
		for(;x<N;x+=x&-x)a[x]+=d;
	}
	
	int sum(int x){
		int ret=0;
		for(;x;x-=x&-x)ret+=a[x];
		return ret;
	}
}B[2];

int main(){
	cin>>T;
	while(T--){
		for(int i=1;i<=n;++i)vx[x[i]]=0;
		for(int i=1;i<=m;++i)vy[y[i]]=0;
		cin>>n>>m>>k;
		for(int i=1;i<=n;++i)scanf("%d",&x[i]),vx[x[i]]=i,cntx[i].clear();
		for(int i=1;i<=m;++i)scanf("%d",&y[i]),vy[y[i]]=i,cnty[i].clear();
		ll ans=0;
		for(int i=1;i<=k;++i){
			scanf("%d%d",&xx[i],&yy[i]);
			int x1=vx[xx[i]],y1=vy[yy[i]];
			if(x1&&y1)continue;
			else if(x1){
				B[1].add(yy[i],1);
				int p=lower_bound(y+1,y+m+1,yy[i])-y;
				ans-=cntx[x1][p];
				cntx[x1][p]++;
			}
			else{
				B[0].add(xx[i],1);
				int p=lower_bound(x+1,x+n+1,xx[i])-x;
				ans-=cnty[y1][p];
				cnty[y1][p]++;
			}
		}
		for(int i=1;i<n;++i){
			int cnt=B[0].sum(x[i+1])-B[0].sum(x[i]);
			ans+=1ll*cnt*(cnt-1)/2;
		}
		for(int i=1;i<m;++i){
			int cnt=B[1].sum(y[i+1])-B[1].sum(y[i]);
			ans+=1ll*cnt*(cnt-1)/2;
		}
		cout<<ans<<endl;
		for(int i=1;i<=k;++i){
			int x1=vx[xx[i]],y1=vy[yy[i]];
			if(x1&&y1)continue;
			else if(x1){
				B[1].add(yy[i],-1);
			}
			else{
				B[0].add(xx[i],-1);
			}
		}
	}
}