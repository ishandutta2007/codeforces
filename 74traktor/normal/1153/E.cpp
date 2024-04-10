#include <bits/stdc++.h>

using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x;
    cin >> n;
    m = n;
    vector < int > to;
    vector < pair < int, int > > out;
    for (int i = 1; i <= n; ++i){
        cout << "? ";
        cout << i << " " << 1 << " " << i << " " << m << endl;
        cin >> x;
        if (x % 2 == 1){
            to.push_back(i);
        }
    }
    if ((int)to.size() == 2){
        for (auto i : to){
            int l = 1, r = m + 1;
            while (r - l > 1){
                int mid = (r + l) / 2;
                cout << "? ";
                cout << i << " " << l << " " << i << " " << mid - 1 << endl;
                cin >> x;
                if (x % 2 == 0) l = mid;
                else r = mid;
            }
            out.push_back({i, l});
        }
        cout << "! ";
        for (auto key : out) cout << key.first << " " << key.second << " ";
        cout << endl;
        return 0;
    }
    for (int j = 1; j <= m; ++j){
        cout << "? ";
        cout << 1 << " " << j << " " << n << " " << j << endl;
        cin >> x;
        if (x % 2 == 1) to.push_back(j);
    }
    int l = 1, r = n + 1;
    while (r - l > 1){
        int mid = (r + l) / 2;
        cout << "? ";
        cout << l << " " << to[0] << " " << mid - 1 << " " << to[0] << endl;
        cin >> x;
        if (x % 2 == 0) l = mid;
        else r = mid;
    }
    out = {{l, to[0]}, {l, to[1]}};
    cout << "! ";
    for (auto key : out) cout << key.first << " " << key.second << " ";
    cout << endl;
    return 0;
}