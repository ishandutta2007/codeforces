#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n[3];
int w[3][N];

ll sqr(int x){
	return 1ll*x*x;
}

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<3;++i)scanf("%d",&n[i]);
		for(int i=0;i<3;++i){
			for(int j=1;j<=n[i];++j){
				scanf("%d",&w[i][j]);
			}
			sort(w[i]+1,w[i]+n[i]+1);
		}
		ll ans=4e18;
		for(int i=0;i<3;++i){
			int x,y;
			if(i==0)x=1,y=2;
			if(i==1)x=0,y=2;
			if(i==2)x=0,y=1;
			for(int j=1;j<=n[i];++j){
				int px=upper_bound(w[x]+1,w[x]+n[x]+1,w[i][j])-w[x]-1;
				if(!px)continue;
				int py=lower_bound(w[y]+1,w[y]+n[y]+1,w[i][j])-w[y];
				if(py>n[y])continue;
				ans=min(ans,sqr(w[i][j]-w[x][px])+sqr(w[i][j]-w[y][py])+sqr(w[x][px]-w[y][py]));
			}
			swap(x,y);
			for(int j=1;j<=n[i];++j){
				int px=upper_bound(w[x]+1,w[x]+n[x]+1,w[i][j])-w[x]-1;
				if(!px)continue;
				int py=lower_bound(w[y]+1,w[y]+n[y]+1,w[i][j])-w[y];
				if(py>n[y])continue;
				ans=min(ans,sqr(w[i][j]-w[x][px])+sqr(w[i][j]-w[y][py])+sqr(w[x][px]-w[y][py]));
			}
		}
		printf("%lld\n",ans);
	}
}