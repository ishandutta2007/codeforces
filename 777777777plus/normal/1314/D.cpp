#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 81;

int n,k;
int d[N][N],ans=1e9;
struct nd{
	int d,p;
	nd(int _d=0,int _p=0){
		d=_d;p=_p;
	}
	friend bool operator < (nd a,nd b){
		return a.d<b.d;
	}
};
nd dis[N][N][N];

void dfs(int x){
	static int vis[N],a[N],tmp;
	if(x==k/2){
		++tmp;
		for(int i=1;i<=k/2-1;++i)vis[a[i]]=tmp;
		vis[1]=tmp;
		a[0]=a[k/2]=1;
		int tot=0;
		for(int i=1;i<=k/2;++i){
			int c=1;
			while(vis[dis[a[i-1]][a[i]][c].p]==tmp)++c;
			if(a[i-1]!=a[i]){
				if(c>n-2)return;
			}
			else{
				if(c>n-1)return; 
			}
			tot+=dis[a[i-1]][a[i]][c].d; 
		}
		ans=min(ans,tot);
		return;
	}
	for(int j=1;j<=n;++j){
		a[x]=j;
		dfs(x+1);
	}
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j){
		cin>>d[i][j];
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j){
		int c=0;
		for(int k=1;k<=n;++k)
		if(k!=i&&k!=j){
			dis[i][j][++c]=nd(d[i][k]+d[k][j],k);
		}
		sort(dis[i][j]+1,dis[i][j]+c+1);
	}
	dfs(1);
	cout<<ans<<endl;
}