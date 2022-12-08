#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n,d[N];
bool g[N][N];


int main(){
	cin>>n;
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		g[x][y]=1;
		g[y][x]=1;
		d[x]++;d[y]++;
	}
	queue<int>q;
	for(int i=1;i<=n;++i)if(d[i]==1)q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(q.empty()){
			printf("! %d\n",x);
			fflush(stdout);
			return 0;
		}
		int y=q.front();q.pop();
		printf("? %d %d\n",x,y);
		fflush(stdout);
		int X;
		cin>>X;
		if(X==x){
			printf("! %d\n",x);
			fflush(stdout);
			return 0;
		}
		if(X==y){
			printf("! %d\n",y);
			fflush(stdout);
			return 0;
		}
		for(int i=1;i<=n;++i)
		if(g[x][i]){
			g[x][i]=g[i][x]=0;
			d[i]--;
			if(d[i]==1)q.push(i);
		}
		for(int i=1;i<=n;++i)
		if(g[y][i]){
			g[y][i]=g[i][y]=0;
			d[i]--;
			if(d[i]==1)q.push(i);
		}
	}
}