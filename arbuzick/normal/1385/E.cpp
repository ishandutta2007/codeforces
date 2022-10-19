#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
vector<vector<int>> g1, g2;
vector<int> used;
bool dfs1(int v){
    used[v] = 1;
    for(auto u: g2[v]){
        if(used[u] == 0)
            dfs1(u);
        if(used[u] == 1)
            return false;
    }
    used[v] = 2;
    return true;
}
vector<int> topsort;
void dfs2(int v){
    used[v] = 1;
    for(auto u: g2[v])
        if(!used[u])
            dfs2(u);
    topsort.pb(v);
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
        int n, m;
        cin >> n >> m;
        g1.assign(n, vector<int>(0));
        g2.assign(n, vector<int>(0));
        vector<pair<int, int>> r;
        for(int i = 0; i < m; ++i){
            int t1, x, y;
            cin >> t1 >> x >> y;
            x--, y--;
            r.pb({x, y});
            if(t1 == 1){
                g1[x].pb(y);
                g2[x].pb(y);
            }else{
                g1[x].pb(y);
                g1[y].pb(x);
            }
        }
        bool ans1 = 1;
        used.assign(n, 0);
        for(int i = 0; i < n; ++i)
            if(used[i] == 0)
                ans1 = ans1&&dfs1(i);
        if(!ans1){
            cout << "NO\n";
            continue;
        }
        used.assign(n, 0);
        topsort.clear();
        for(int i = 0; i < n; ++i)
            if(!used[i])
                dfs2(i);
        reverse(topsort.begin(), topsort.end());
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            a[topsort[i]] = i;
        //for(int i = 0; i < n; ++i)
          //  cout << topsort[i] << ' ';
        //cout << '\n';
        for(int i = 0; i < m; ++i)
            if(a[r[i].first] > a[r[i].second])
                swap(r[i].first, r[i].second);
        cout << "YES\n";
        for(auto [x, y]: r)
            cout << x+1 << ' ' << y+1 << '\n';
	}
	return 0;
}