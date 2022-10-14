#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    set<pii> s;
    int x = 0, y = 0;
    for (int i = 0; i <= k; i++) {
        s.insert({x, y});
        s.insert({x + 1, y});
        s.insert({x, y + 1});
        s.insert({x + 1, y + 1});
        x++;
        y++;
    }
    cout << s.size() << "\n";
    for (auto &c : s) cout << c.fi << " " << c.se << "\n";
    return 0;
}