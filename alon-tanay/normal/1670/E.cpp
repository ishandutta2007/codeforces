#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<int,int>
#define pl pair<ll,ll>
#define f first
#define s second

using namespace std;

struct Ne {
    int node, ref;
};

vector<Ne> nei[131074];
int cur_val;

vector<int> node_vals(131074);
vector<int> edge_vals(131074);
int n;

void dfs(int node, bool ev = true, int par = -1) {
    for(Ne ne : nei[node]) {
        if(ne.node == par) { continue; }
        if(ev) {
            edge_vals[ne.ref] = n + cur_val;
            node_vals[ne.node] = cur_val;
        } else {
            edge_vals[ne.ref] = cur_val;
            node_vals[ne.node] = n + cur_val;
        }
        cur_val ++;
        dfs(ne.node,!ev,node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int p;
        cin >> p;
        cur_val = 1;
        n = 1<<p;
        for(int i = 0; i <= n; i ++) {
            nei[i].clear();
        }
        for(int i = 1; i < n; i ++) {
            int a, b;
            cin >>a >> b;
            nei[a].push_back({b,i});
            nei[b].push_back({a,i});
        }
        node_vals[1] = n;
        dfs(1);
        cout << "1\n";
        for(int i = 1; i <= n; i ++) {
            cout << node_vals[i] << " ";
        }
        cout << "\n";
        for(int i = 1; i < n; i ++) {
            cout << edge_vals[i] << " ";
        }
        cout << "\n";
        
    }
    return 0;
}