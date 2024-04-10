#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define st first
#define nd second
#define mp(x, y) make_pair(x, y)
using namespace std;
const int N=1e5+5;
struct edge{
	int flo, cap, v, u;
	edge(int _flo, int _cap, int _v, int _u) : flo(_flo), cap(_cap), v(_v), u(_u){}
};
vector<edge> edg;
vector<int> E[N];
int s, t;
void add_edge(int u, int v , int c){
	//cout<<u<<" "<<v<<" "<<c<<"\n";	
	E[u].pb(edg.size());
	edg.pb(edge(0, c, u, v));
	E[v].pb(edg.size());
	edg.pb(edge(0, 0, v, u));

}
int par[N], d[N];
int bfs(){
	vector<int> V;
	d[s]=1, par[s]=-1;
	V.pb(s);
	for(int i=0; i<V.size(); i++){
		int v=V[i];
		//cout<<v<<"\n";
		for(int e:E[v]){
			//cout<<edg[e].v<<" "<<edg[e].u<<" "<<edg[e].flo<<" "<<edg[e].cap<<"\n";
			if(!d[edg[e].u] && edg[e].flo!=edg[e].cap){
				par[edg[e].u]=e;
				d[edg[e].u]=d[v]+1;
				V.pb(edg[e].u);
			}
		}
	}
	//cout<<"\n";
	for(int i:V)if(i!=t)d[i]=0;
	if(!d[t])return 0;
	d[t]=0;
	int ans=1e9;
	int v=t;
	while(v!=s){
		ans=min(ans, edg[par[v]].cap-edg[par[v]].flo);
		v=edg[par[v]].v;
	}
	v=t;
	while(v!=s){
		edg[par[v]].flo+=ans;
		edg[par[v]^1].flo-=ans;
		v=edg[par[v]].v;
	}
	//cout<<"a "<<ans<<"\n";
	return ans;
}
int flow(){
	int ans=0;
	while(int k=bfs())ans+=k;
	return ans;
}
int main(){
	int m;
	cin>>m;
	cin>>m;
	vector<pair<pair<int, int>, pair<int, int> > > V(m);
	vector<int> X, Y;
	for(auto &i:V){
		cin>>i.st.st>>i.nd.st>>i.st.nd>>i.nd.nd;
		i.st.nd++;
		i.nd.nd++;
		X.pb(i.st.st);
		X.pb(i.st.nd);
		Y.pb(i.nd.st);
		Y.pb(i.nd.nd);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	vector<pair<int, int> > V2;
	for(auto p:V){
		for(int i=0; i<X.size(); i++){
			for(int j=0; j<Y.size(); j++){
				if(p.st.st<=X[i] && X[i]<p.st.nd && p.nd.st<=Y[j] && Y[j]<p.nd.nd){
					V2.pb(mp(i, j));
				}
			}
		}
	}
	//cout<<V2.size()<<"\n";
	sort(V2.begin(), V2.end());
	V2.resize(unique(V2.begin(), V2.end())-V2.begin());
	s=0;
	t=int(X.size()+Y.size())-1;
	for(int i=0; i+1<X.size(); i++){
		add_edge(s, i+1, X[i+1]-X[i]);
	}
	for(int i=0; i+1<Y.size();i++){
		add_edge(X.size()+i, t, Y[i+1]-Y[i]);
	}
	for(pair<int, int> i:V2){
		add_edge(i.st+1, i.nd+X.size(), 1e9);
	}
	cout<<flow();
}