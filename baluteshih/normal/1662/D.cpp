#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int cnt[3] = {};
        string a, b;
        cin >> a >> b;
        for (char c : a)
            cnt[int(c - 'A')] ^= 1;
        for (char c : b)
            cnt[int(c - 'A')] ^= 1;
        if (cnt[0] || cnt[1] || cnt[2]) {
            cout << "NO\n";
            continue;
        }
        string p, q;
        for (char c : a)
            if (c != 'B') {
                if (!p.empty() && p.back() == c)
                    p.pop_back();
                else
                    p.pb(c);
            }
        for (char c : b)
            if (c != 'B') {
                if (!q.empty() && q.back() == c)
                    q.pop_back();
                else
                    q.pb(c);
            }
        if (p == q)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}