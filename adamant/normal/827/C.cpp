#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    map<char, int> to_int = {{'A', 0}, {'C', 1}, {'T', 2}, {'G', 3}};
    ordered_set pos[4][11][10];
    for(int i = 0; i < s.size(); i++)
    {
        int c = to_int[s[i]];
        for(int j = 1; j <= 10; j++)
            pos[c][j][i % j].insert(i);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int x;
            char c;
            cin >> x >> c;
            x--;
            char tc = c;
            if(c != s[x])
            {
                c = to_int[s[x]];
                for(int j = 1; j <= 10; j++)
                    pos[c][j][x % j].erase(x);
                s[x] = tc;
                c = to_int[s[x]];
                for(int j = 1; j <= 10; j++)
                    pos[c][j][x % j].insert(x);
            }
        }
        else
        {
            int l, r;
            string t;
            cin >> l >> r >> t;
            l--;
            int ans = 0;
            for(int z = 0; z < t.size(); z++)
                ans += pos[to_int[t[z]]][t.size()][(l + z) % t.size()].order_of_key(r) -
                       pos[to_int[t[z]]][t.size()][(l + z) % t.size()].order_of_key(l);
            cout << ans << "\n";
        }
    }
}