#include<bits/stdc++.h>
#define N 500100
using namespace std;
vector<int> g[N],ans[N];
bool vis[N];
int main(){
	int n;
	bool flag=false;
	scanf("%d",&n);
	for(int i=0;i<n+n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(g[i].size()!=4) flag=true;
	}
	if(flag){
		puts("-1");
		return 0;
	}
	if(n<=6){
		if(n<=5){
			for(int i=1;i<=5;i++) printf("%d ",i);
		}
		else{
			bool v[7][7]={};
			for(int i=1;i<=6;i++){
				for(int j=0;j<4;j++){
					v[i][g[i][j]]=true;
				}
			}
			int out[3];
			for(int j=0;j<3;j++){
				for(int k=1;k<=6;k++){
					bool con=false;
					for(int l=0;l<j;l++){
						if(out[l]==k || !v[k][out[l]]){
							con=true;
							continue;
						}
					}
					if(con) continue;
					out[j]=k;
					printf("%d ",k);
					break;
				}
			}
			for(int j=0;j<3;j++){
				for(int k=1;k<=6;k++){
					if(!v[k][out[j]]&&k!=out[j]){
						printf("%d ",k);
						break;
					}
				}
			}
		}
		puts("");
		return 0;
	}
	/*else if(n==6){
		int op[7]={};
		for(int i=1;i<7;i++){
			int now=1;
			bool bad[7]={};
			for(int j=0;j<4;j++){
				bad[g[i][j]]=true;
			}
			while(now==i||bad[now]) now++;
			op[i]=now;
		}
		for(int i=1;i<=6;i++){
			if(op[i]!=)
		}
	}*/
	for(int u=1;u<=n;u++){
		for(int i=0;i<4;i++){
			int v=g[u][i];
			int cnt=0;
			for(int k=0;k<4;k++){
				int w=g[v][k];
				for(int l=0;l<4;l++){
					if(w==g[u][l]) cnt++; 
				}
			}
			if(cnt>=2) ans[u].push_back(v);
		}
		if(ans[u].size()!=2) flag=true;
	}
	int now=1;
	vector<int> c;
	for(int i=0;i<n&&!flag;i++){
		if(vis[now]){
			flag=true;
			break;
		}
		c.push_back(now);
		vis[now]=true;
		for(int j=0;j<2;j++){
			if(!vis[ans[now][j]]){
				now=ans[now][j];
				break;
			}
		}
	}
	if(c.size()==n&&!flag){
		for(int i=0;i<n;i++){
			if(g[c[i]].size()!=4) flag=true;
			else{
				vector<int> tmp;
				for(int k=-2;k<=2;k++){
					if(k) tmp.push_back(c[(i+k+n)%n]);
				}
				sort(tmp.begin(),tmp.end());
				sort(g[c[i]].begin(),g[c[i]].end());
				for(int j=0;j<4;j++){
					if(g[c[i]][j]!=tmp[j]){
						flag=true;
						break;
					}
				}
			}
		}
		if(flag) puts("-1");
		else{
			for(int i=0;i<n;i++) printf("%d ",c[i]);
		}
		puts("");
	}
	else{
		puts("-1");
	}
	return 0;
}