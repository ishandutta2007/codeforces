#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;

bool easy_win(ll s, ll e) {
    if (e % 2 == 1) {
        if (s % 2 == 1) return 0;
        else return 1;
    }
    if (s > e / 2) {
        if (s % 2 == 1) return 1;
        else return 0;
    }
    if (s > e / 4) return 1;
    return easy_win(s, e / 4);
}

bool easy_lose(ll s, ll e) {
    if (s * 2 > e) return 1;
    return easy_win(s, e / 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector<pair<int, int>> lol(t);
    for (int i = 0; i < t; i++) {
        ll s, e;
        cin >> s >> e;
        lol[i] = {easy_win(s, e), easy_lose(s, e)};
    }
    int l = 1, w = 0;
    for (int i = 0; i < t; i++) {
        if (l == 1 && w == 1) break;
        if (l == 0 && w == 0) break;
        if (w == 1) lol[i].fi ^= 1, lol[i].se ^= 1;
        l = lol[i].se, w = lol[i].fi;
    }
    cout << w << " " << l;
    return 0;
}