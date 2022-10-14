#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define test(x) cout << #x << ' ' << x << endl
#define printv(x) { \
    for (auto a : x) cout << a << ' '; \
    cout << endl; \
}
#define pii pair<int, int>
#define pll pair<lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int N = 5001, abc = 864197532;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector <lli> a(n), b(n);
    lli ans = 0;
    for (int i = 0; i < n; ++i) if (s[i] == '?') {
        cin >> a[i] >> b[i];
        ans += b[i];
    }
    string t = s;
    for (char &c : t) if (c == '?') c = ')';
    priority_queue <pair<lli, int>> pq;
    int now = 0;
    bool fail = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') pq.emplace(b[i] - a[i], i);
        if (s[i] == '(') now++;
        else now--;
        if (now < 0) {
            if (pq.empty()) {
                fail = true;
                break;
            }
            auto a = pq.top(); pq.pop();
            ans -= a.X;
            t[a.Y] = '(';
            now += 2;
        }
    }
    if (fail || now != 0) {
        cout << "-1\n";
    } else {
        cout << ans << endl << t << endl;
    }
}