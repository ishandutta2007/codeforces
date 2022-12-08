#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pi pair<int,int>
#define f first
#define s second

using namespace std;
using namespace __gnu_pbds;

typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pbds locs;
    int n, m;
    cin >> n >> m;
    vector<int> perm(n+1);
    vector<int> loc(n+1);
    for(int i = 1; i <= n; i ++) {
        locs.insert({i,i});
    }
    int cur_idx = 0;
    bool fail = false;
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        auto it = locs.find_by_order(y-1);
        if((perm[it->s] && perm[it->s] != x) || (loc[x] && loc[x] != it->s)) {
            fail = true;
        } else {
            perm[it->s] = x;
            loc[x] = it->s;
        }
        locs.insert({--cur_idx,it->s});
        locs.erase(it);
    }
    if(fail) {
        cout << "-1";
        return 0;
    }
    stack<int> lft;
    for(int i = n; i; i --) {
        if(!loc[i]) {
            lft.push(i);
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(perm[i]) {
            cout << perm[i] << " ";
        } else {
            cout << lft.top() << " ";
            lft.pop();
        }
    }
    return 0;
}