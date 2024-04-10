#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
 
int n,m,d[N],fr[N],to[N];
vector<int> g[N],que;
 
bool topsort(){
	queue<int> q;
	for(int i=1;i<=n;++i)
	if(!d[i]){
		q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		que.push_back(x);
		for(int i=0;i<g[x].size();++i){
			int y=g[x][i];
			d[y]--;
			if(!d[y]){
				q.push(y);
			}
		}
	}
	return que.size()==n;
}
 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		d[y]++;
	}
	if(!topsort()){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;++i)fr[i]=to[i]=i;
	for(int i=0;i<que.size();++i){
		int x=que[i];
		for(int j=0;j<g[x].size();++j){
			int y=g[x][j];
			fr[y]=min(fr[y],fr[x]);
		}
	}
	for(int i=(int)que.size()-1;~i;--i){
		int x=que[i];
		for(int j=0;j<g[x].size();++j){
			int y=g[x][j];
			to[x]=min(to[x],to[y]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)if(fr[i]==i&&to[i]==i)ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
	if(fr[i]==i&&to[i]==i)putchar('A');
	else putchar('E');
	printf("\n");
}