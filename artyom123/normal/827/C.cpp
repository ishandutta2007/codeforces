#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

int main() {

    string s;
    cin >> s;
    int n = s.size();
    map <char, int> num;
    num['A'] = 0;
    num['T'] = 1;
    num['G'] = 2;
    num['C'] = 3;
    vector <vector<vector<ordered_set>>> g(4, vector<vector<ordered_set>>(11, vector<ordered_set>(11)));
    for (int i = 0; i < n; i++) {
        int ind = num[s[i]];
        for (int mod = 1; mod <= 10; mod++) {
            g[ind][mod][i % mod].insert(i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            string e;
            cin >> e;
            int mod = e.size();
            int ans = 0;
            for (int i = 0; i < e.size(); i++) {
                int ind = num[e[i]];
                ans += g[ind][mod][(l + i) % mod].order_of_key(r) - g[ind][mod][(l + i) % mod].order_of_key(l);
            }
            cout << ans << "\n";
        } else {
            int pos;
            cin >> pos;
            pos--;
            char c;
            cin >> c;
            int ind = num[c];
            int prev_ind = num[s[pos]];
            s[pos] = c;
            for (int mod = 1; mod <= 10; mod++) {
                g[prev_ind][mod][pos % mod].erase(pos);
            }
            for (int mod = 1; mod <= 10; mod++) {
                g[ind][mod][pos % mod].insert(pos);
            }
        }
    }
    return 0;
}