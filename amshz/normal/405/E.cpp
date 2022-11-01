#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long       ll;
typedef long double     ld;
typedef string          str;
 
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll MAX1 = 2e5+7,
	     MOD = 998244353;
 
ll n, m, x, y, mark[MAX1], parent[MAX1], ft[MAX1];
set <ll> bach[MAX1], pack[MAX1];
vector <ll> adj[MAX1];
vector <pair<ll, pair<ll, ll> > > ans;
 
 
void DFS(ll v, ll par){
    mark[v] = 1;
    for (int i = 0; i < adj[v].size(); i++){
        int u = adj[v][i];
        if (mark[u] && u != par && !ft[u]) pack[v].insert(u);
        if (mark[u]) continue;
        parent[u] = v;
        bach[v].insert(u);
        DFS(u, v);
    }
    ll flag = -1;
    for (int i : bach[v]){
        if (flag == -1) flag = i;
        else{
            ans.push_back({flag, {v, i}});
            flag = -1;
        }
    }
    if (!par)   return ;
    if (flag != -1 && pack[v].size()){
        int u = *pack[v].begin();
        ans.push_back({flag, {v, u}});
        pack[v].erase(u);
        pack[u].erase(v);
        flag = -1;
    }
    while (pack[v].size() >= 2){
        int u1 = *pack[v].begin();
        pack[v].erase(u1);
        pack[u1].erase(v);
        int u2 = *pack[v].begin();
        pack[v].erase(u2);
        pack[u2].erase(v);
        ans.push_back({u1, {v, u2}});
    }
    if (pack[v].size() && par){
        int u = *pack[v].begin();
        pack[v].erase(u);
        pack[u].erase(v);
        ans.push_back({u, {v, par}});
        bach[par].erase(v);
    }
    if (flag >= 0){
        int u = flag;
        ans.push_back({u, {v, parent[v]}});
        bach[parent[v]].erase(v);
    }
    ft[v] = 1;
}
 
int main(){
	fast_io;
	cin >> n >> m;
	int mm = m;
	while (mm--){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i){
        if (!mark[i])   DFS(i, 0);
	}
	if (m%2){
		cout << "No solution" << endl;
		return 0;
	}
	for (int i = 0; i < ans.size(); ++i){
        cout << ans[i].A << sep << ans[i].B.A << sep << ans[i].B.B << '\n';
	}
	return 0;
}
/*                 now or never                 */