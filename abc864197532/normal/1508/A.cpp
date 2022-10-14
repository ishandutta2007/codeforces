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
const int N = 500001, abc = 864197532, K = 700;

string ans;

void chk(string s, string t, int n) {
    char cur;
    if (count(all(s), '0') >= n && count(all(t), '0') >= n) cur = '0';
    else if (count(all(s), '1') >= n && count(all(t), '1') >= n) cur = '1';
    else return;
    vector <int> cnt(n + n + 1, 0);
    int now = 0;
    for (int i = 0; i < n + n; ++i) {
        if (s[i] == cur) now++;
        else cnt[now]++;
    }
    int mx = now;
    now = 0;
    for (int i = 0; i < n + n; ++i) {
        if (t[i] == cur) now++;
        else cnt[now]++;
    }
    mx = max(mx, now);
    ans.clear();
    for (int i = 0; i <= mx; ++i) {
        for (int j = 0; j < cnt[i]; ++j) ans.pb(cur ^ 1);
        ans.pb(cur);
    }
    ans.pop_back();
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;
        chk(a, b, n);
        chk(b, c, n);
        chk(a, c, n);
        cout << ans << endl;
    }
}