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
    ll k;
    cin >> k;
    vector<int> now(10);
    string s = "codeforces";
    for (int i = 0; ; i++) {
        if (i == 10) i = 0;
        now[i]++;
        ll ans = 1;
        for (auto &c : now) ans *= c;
        if (ans >= k) break;
    }
    for (int i = 0; i < 10; i++) {
        while (now[i] > 0) {
            now[i]--;
            cout << s[i];
        }
    }
    return 0;
}