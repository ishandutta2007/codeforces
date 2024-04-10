#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int int64_t

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    set<pair<int, int>> num_pos;
    ordered_set poses;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        num_pos.insert({a[i], i});
        poses.insert(i);
    }
    int start = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int num = begin(num_pos)->first;
        auto it = num_pos.lower_bound(make_pair(num, start));
        if(it == end(num_pos) || it->first != num)
            it = begin(num_pos);
        if(it->second >= start)
            ans += poses.order_of_key(it->second + 1) - poses.order_of_key(start);
        else
            ans += poses.size() - poses.order_of_key(start) + poses.order_of_key(it->second + 1);
        start = (it->second + 1) % n;
        poses.erase(it->second);
        num_pos.erase(it);
    }
    cout << ans << endl;
    return 0;
}