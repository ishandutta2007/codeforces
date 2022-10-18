#include <bits/stdc++.h>

using namespace std;

pair < int, int > a[300005];
int b[300005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        a[i] = {x, i};
    }
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    vector < vector < int > > out;
    vector < pair < int, int > > q;
    for (int i = n; i >= 1; --i){
        if (a[i].first > b[i]){
            q.push_back({a[i].second, a[i].first - b[i]});
        }
        else if (a[i].first < b[i]){
            int t = b[i] - a[i].first;
            while ((int)q.size() > 0 && t > 0){
                auto p = q.back();
                int imin = min(p.second, t);
                out.push_back({a[i].second, p.first, imin});
                t -= imin;
                q.back().second -= imin;
                if (q.back().second == 0) q.pop_back();
            }
            if (t != 0){
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    if ((int)q.size() != 0){
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    cout << out.size() << '\n';
    for (auto key : out) cout << key[0] << " " << key[1] << " " << key[2] << '\n';
    return 0;
}