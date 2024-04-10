#include <bits/stdc++.h>

using namespace std;

set < int > pos[100];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, cnt = 0;
    cin >> n;
    vector < int > a = {4,8,15,16,23,42};
    for (int i = 1; i <= n; ++i){
        cin >> x;
        pos[x].insert(i);
    }
    int last = 0, my_pos = 0;
    while (1){
        if ((int)pos[a[last]].size() == 0) break;
        auto it = pos[a[last]].lower_bound(my_pos);
        if (it == pos[a[last]].end()) break;
        my_pos = (*it);
        pos[a[last]].erase(my_pos);
        last++;
        if (last == 6){
            cnt++;
            last = 0;
            my_pos = 0;
        }
    }
    cout << n - 6 * cnt << '\n';
    return 0;
}