#include<bits/stdc++.h>
#define N 300100
using namespace std;
int a[N],b[N],d[N],p[N];
vector<int> seg[N*2];
vector<int> g[N];
queue<int> bfs_que;
void add(int l,int r,int n,int id){
	l+=n,r+=n;
	while(l<r){
		if(l&1) seg[l++].push_back(id);
		if(r&1) seg[--r].push_back(id);
		l>>=1,r>>=1;
	}
}
void qry(int s, int n, int pd){
	int st=s;
	s+=n;
	while(s){
		for(auto x:seg[s]){
			if(d[x]<0){
				p[x]=st;
				d[x]=pd+1;
				bfs_que.push(x);
			}
		}
		seg[s].clear();
		s>>=1;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) d[i]=-1;
	g[0].push_back(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(i-a[i],i+1,n+1,i);
	}
	for(int j=1;j<=n;j++){
		scanf("%d",&b[j]);
		g[j+b[j]].push_back(j);
	}
	bfs_que.push(0);
	while(!bfs_que.empty()){
		int u=bfs_que.front();
		bfs_que.pop();
		for(auto x:g[u]){
			qry(x,n+1,d[u]);
		}
	}
	vector<int> ans;
	printf("%d\n",d[n]);
	if(d[n]>=0){
		int now=n;
		while(now>0){
			printf("%d ",p[now]);
			now=p[now]+b[p[now]];
		}
		puts("");
	}
	return 0;
}