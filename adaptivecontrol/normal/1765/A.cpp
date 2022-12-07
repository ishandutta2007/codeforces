#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,cap,cst,rev;
};
vector<edge>g[1003];
void add_edge(int x,int y,int cap,int cst){
	g[x].push_back((edge){y,cap,cst,g[y].size()});
	g[y].push_back((edge){x,0,-cst,g[x].size()-1});
}
int prevv[1003],preve[1003];
int dist[1003];
int min_cost_flow(int s,int t){
	int ret=0;
	while(1){
		memset(dist,31,sizeof(dist));
		priority_queue<pair<long long,int> >Q;
		dist[s]=0;
		Q.push(make_pair(0,s));
		while(Q.size()){
			long long len=-Q.top().first;
			int nw=Q.top().second;Q.pop();
			if(dist[nw]<len)continue;
			for(int i=0;i<g[nw].size();i++){
				edge &e=g[nw][i];
				if(e.cap>0&&dist[e.to]>dist[nw]+e.cst)
					dist[e.to]=dist[nw]+e.cst,
					prevv[e.to]=nw,preve[e.to]=i,
					Q.push(make_pair(-dist[e.to],e.to));
			}
		}
		if(dist[t]>=0)break;
		int f=2333;
		for(int v=t;v!=s;v=prevv[v])
			f=min(f,g[prevv[v]][preve[v]].cap);
		ret+=f;
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=g[prevv[v]][preve[v]];
			e.cap-=f,g[v][e.rev].cap+=f;
		}
	}return ret;
}
int n,m,N;
bitset<500>st[503],ST[503];
int tp[503],ans[503][503],val[503],nxt[503];
bool ok[503];
map<long long,int>mp;
long long W[503];
mt19937 rng(time(0));
long long hsh(bitset<500>_st){
	long long ret=0;
	for(int i=0;i<n;i++)
		if(_st[i])
			ret^=W[i];
	return ret;
}
int main(){
	for(int i=0;i<503;i++)
		W[i]=(rng()*1ll<<32|rng());
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			char c;
			cin>>c;
			if(c=='1')
				st[j][i]=1;
		}
	for(int i=0;i<m;i++)
		if(mp.find(hsh(st[i]))==mp.end())
			ST[N]=st[i],
			mp[hsh(st[i])]=N++;
	int S=N+N,T=N+N+1;
	for(int i=0;i<N;i++)
		add_edge(S,i+i,1,0),
		add_edge(i+i+1,T,1,0),
		add_edge(i+i,i+i+1,1,-1);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(i!=j&&(ST[i]&ST[j])==ST[j])
				add_edge(i+i+1,j+j,1,0);
	min_cost_flow(S,T);
	memset(nxt,-1,sizeof(nxt));
	for(int i=0;i<N;i++)
		for(int j=0;j<g[i+i+1].size();j++)
			if(!g[i+i+1][j].cst&&g[i+i+1][j].to/2!=i&&g[i+i+1][j].to/2!=N&&!g[i+i+1][j].cap)
				nxt[i]=g[i+i+1][j].to/2,
				ok[g[i+i+1][j].to/2]=1;
	int k=0;
	for(int i=0;i<N;i++)
		if(!ok[i]){
			int j=i,l=0;
			while(j!=-1){
				tp[j]=k;
				val[j]=l++;
				for(int o=0;o<n;o++)
					if(ST[j][o])
						ans[o][k]++;
				j=nxt[j];
			}k++;
		}
	cout<<k<<'\n';
	for(int i=0;i<m;i++)
		cout<<tp[mp[hsh(st[i])]]+1<<' ';cout<<'\n';
	for(int i=0;i<m;i++)
		cout<<val[mp[hsh(st[i])]]+2<<' ';cout<<'\n';
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++)
			cout<<ans[i][j]+1<<' ';
		cout<<'\n';
	}
}