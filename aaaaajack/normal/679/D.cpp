#include<bits/stdc++.h>
#define N 410
using namespace std;
int dis[N][N],deg[N];
vector<int> v[N];
double pr[N][N];
double mx[N];
int num[N],sz;
bool in[N];
int main(){
	int n,m,x,y;
	double ans=0;
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<n;i++) dis[i][i]=0;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		dis[x][y]=dis[y][x]=1;
		deg[x]++;
		deg[y]++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(dis[j][i]+dis[i][k]<dis[j][k]){
					dis[j][k]=dis[j][i]+dis[i][k];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		double tans=0;
		memset(pr,0,sizeof(pr));
		for(int j=0;j<n;j++){
			v[j].clear();
		}
		for(int j=0;j<n;j++){
			v[dis[i][j]].push_back(j);
		}
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(dis[j][k]==1){
					pr[dis[i][j]][k]+=1.0/n/deg[j];
				}
			}
		}
		for(int j=0;j<n;j++){
			if(v[j].empty()) continue;
			double tmp=1.0/n;
			for(int k=0;k<n;k++){
				double t2=0;
				for(int d=max(j-1,0);d<=j+1;d++){
					for(int l=0;l<v[d].size();l++){
						int u=v[d][l];
						if(pr[j][u]>mx[dis[u][k]]){
							mx[dis[u][k]]=pr[j][u];
							if(!in[dis[u][k]]){
								in[dis[u][k]]=true;
								num[sz++]=dis[u][k];
							}
						}
					}
				}
				for(int l=0;l<sz;l++){
					t2+=mx[num[l]];
					mx[num[l]]=0;
					in[num[l]]=false;
				}
				sz=0;
				tmp=max(t2,tmp);
			}
			tans+=tmp;
		}
		ans=max(ans,tans);
	}
	printf("%.10f\n",ans);
	return 0;
}