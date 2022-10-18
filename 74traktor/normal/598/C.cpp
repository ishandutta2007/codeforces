#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector < pair < int, int > > a;
    int n, x, y;
    cin >> n;
    map < pair < int, int >, int > rev;
    for (int i = 1; i <= n; ++i){
        cin >> x >> y;
        rev[{x, y}] = i;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end(), [](pair < int, int > x, pair < int, int > y) {
        if (x.second < 0 && y.second >= 0) return false;
        if (y.second < 0 && x.second >= 0) return true;
        if (x.second == 0 && y.second == 0){
            return x.first > y.first;
        }
        return x.first * y.second - x.second * y.first > 0;
    });
    pair < int, int > out = {0, 1};
    for (int i = 0; i < (int)a.size(); ++i){
        int nxt = i + 1;
        if (nxt == (int)a.size()) nxt = 0;
        pair < int, int > t1 = a[out.first], t2 = a[out.second];
        int v1 = t1.first * t2.second - t1.second * t2.first, sc1 = t1.first * t2.first + t1.second * t2.second;
        int v2 = a[i].first * a[nxt].second - a[i].second * a[nxt].first, sc2 = a[i].first * a[nxt].first + a[i].second * a[nxt].second;
        if (v2 == 0) continue;
        if (v2 < 0){
            v2 *= (-1);
        }
        if (v1 < 0){
            v1 *= (-1);
        }
        if (sc2 * v1 > sc1 * v2 || (v1 == 0 && sc2 * v2 >= 0)) out = {i, nxt};
    }
    cout << rev[a[out.first]] << " " << rev[a[out.second]] << '\n';
    return 0;
}