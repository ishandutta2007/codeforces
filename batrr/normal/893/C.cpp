#include <iostream>
#include <vector>
#include <set>
#define pb push_back
using namespace std;
const int maxn=1e6+123;
int n,m,a[maxn];
long long ans=0;
vector<int> g[maxn];
bool used[maxn];
vector<int> comp;
 
void dfs (int v) {
	used[v] = true;
	comp.push_back (v);
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (! used[to])
			dfs (to);
	}
}
 
void find_comps() {
	
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (! used[i]) {
			comp.clear();
			dfs (i);
 			int an=1e9+7;
		//	cout << "Component:";
			for (size_t j=0; j<comp.size(); ++j){
				an=min(an,a[comp[j]]);
		//		cout << ' ' << comp[j];
			}
			ans+=an;
	//		cout<<' '<<an<<endl;
		}
}	
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++){
		int q,w;
		cin>>q>>w;
		q--,w--;
		g[q].pb(w);
		g[w].pb(q);	
	}
	find_comps();
	cout<<ans;
}