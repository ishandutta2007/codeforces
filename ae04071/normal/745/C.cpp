#include <stdio.h>
#include <vector>
#include <queue>

int n,m,k;
std::vector<int> adj[1001];
int con[1001];

int no_size[1001];
int ed_size[1001];
bool vis[1001];

void BFS(int node, int s)
{
	vis[node]=true;

	std::queue<int> que;
	que.push(node);
	while(!que.empty()) {
		int h=que.front();que.pop();
		no_size[s]++;
		for(auto &it:adj[h]) {
			if(!vis[it]) {
				vis[it]=true;
				que.push(it);
			}
			ed_size[s]++;
		}
	}
}

void BFS2(int node, int &ns, int &es)
{
	vis[node]=true;

	std::queue<int> que;
	que.push(node);
	while(!que.empty()) {
		int h=que.front();que.pop();
		ns++;
		for(auto &it:adj[h]) {
			if(!vis[it]) {
				que.push(it);
				vis[it]=true;
			}
			es++;
		}
	}
}



void DFS(int node, int s)
{
	vis[node]=true;
	no_size[s]++;
	for(auto& it:adj[node]) {
		if(!vis[it]) DFS(it,s);
		ed_size[s]++;
	}
}

void DFS2(int node, int &ns, int &es)
{
	vis[node]=true;
	ns++;
	for(auto &it:adj[node]) {
		if(!vis[it]) DFS2(node, ns, es);
		es++;
	}
}

int main()
{
	scanf("%d %d %d", &n,&m,&k);
	for(int i=0;i<k;i++) scanf("%d",con+i);

	int u,v;
	for(int i=0;i<m;i++) {
		scanf("%d %d", &u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=0;i<k;i++) {
		BFS(con[i], i);
	}

	int max=0,idx=-1;
	for(int i=0;i<k;i++) {
		if(max < no_size[i]) { 
			max=no_size[i];
			idx=i;
		}
	}

	int ns=0,es=0;
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			ns=0;es=0;
			BFS2(i,ns,es);
			no_size[idx]+=ns;
			ed_size[idx]+=es;
		}
	}

	long long sum=0;
	for(int i=0;i<k;i++) {
		sum += ((long long)(no_size[i]) * (no_size[i]-1)) / 2;
		sum -= ed_size[i]/2;
	}

	printf("%lld\n",sum);

	return 0;
}