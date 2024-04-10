#include<bits/stdc++.h>
#define ll long long
#define N 200015
using namespace std;
int n,m,k,h1[N],h2[N],cnt,s[N],dis[N],sum[N],a1,a2;
queue<int> q;
struct edge{
	int to,next;
	edge(){}
	edge(int a,int b){to = a;next = b;}
}e1[N],e2[N];
void add(int u,int v){
	e1[++cnt] = edge(v,h1[u]);h1[u] = cnt;
	e2[cnt] = edge(u,h2[v]),h2[v] = cnt;
}
void bfs(){
	memset(dis,0x3f,sizeof(dis));
	q.push(s[k]);
	dis[s[k]] = 0;
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int i = h2[u];i;i = e2[i].next){
			int v = e2[i].to;
			if(dis[v] > dis[u]+1){
				dis[v] = dis[u]+1;
				sum[v] = 1;
				q.push(v);
			}else{
				if(dis[v] == dis[u]+1){
					sum[v]++;
				}
			}
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	scanf("%d",&k);
	for(int i = 1;i <= k;++i) scanf("%d",&s[i]);
	bfs();
	for(int i = 1;i < k;++i){
	//	cout << dis[s[i]] << ' ' << dis[s[i+1]]  << ' ' << sum[s[i]] << endl;
		if(dis[s[i]]!=dis[s[i+1]]+1) a1++,a2++;
		else{
			if(sum[s[i]]>1) a2++;
		}
	}
	printf("%d %d",a1,a2);
	return 0;
}