#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<pii> es(m);
	trav(p, es) cin >> p.first >> p.second;
	vector<vi> gr(n);
	trav(p, es) --p.first, --p.second;
	rep(i,0,m){
		gr[es[i].first].push_back(i);
		gr[es[i].second].push_back(i);
	}
	vi sum(m);
	rep(i,0,m) sum[i] = es[i].first + es[i].second;
	vi ori(m, -1), deg(n);
	int ans = 0;
	rep(i,0,m){
		pii p = es[i];
		if(min(deg[p.first],deg[p.second]) < ans){
			if(deg[p.first]<deg[p.second]){
				ori[i] = p.second;
				++deg[p.first];
			} else {
				ori[i] = p.first;
				++deg[p.second];
			}
			continue;
		}
		vector<int> pek(n,-1);
		stack<int> st;
		st.push(p.first);
		pek[p.first] = 0;
		ori[i] = p.second;
		++deg[p.first];
		while(!st.empty()){
			int v = st.top(); st.pop();
			if(deg[v]<ans){
				++deg[v];
				--deg[p.first];
				while(v != p.first)
					v = ori[pek[v]] = sum[pek[v]] - v;
				break;
			}
			trav(j, gr[v]) if(j<=i && v != ori[j]){
				int u = sum[j]-v;
				if(pek[u]==-1){
					pek[u] = j;
					st.push(u);
				}
			}
		}
		ans = max(ans, deg[p.first]);
	}
	cout << ans << endl;
	rep(i,0,m){
		cout << 1+sum[i]-ori[i] << ' ' << 1+ori[i] << endl;
	}
}