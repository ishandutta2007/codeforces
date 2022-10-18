#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, cnt[26] = {};
    ll t;
    string s;
    cin >> n >> t >> s;
    for (int i = 0; i < n - 2; ++i)
        ++cnt[int(s[i] - 'a')];
    t -= (1LL << int(s[n - 1] - 'a')) - (1LL << int(s[n - 2] - 'a'));
    t = abs(t);
    for (ll i = 0; i < 26; ++i)
        t += (1LL << i) * cnt[i];
    for (ll i = 26; i > 0; --i)
        if ((t >> i) > cnt[i - 1])
            t -= (1LL << i) * cnt[i - 1];
        else
            t %= (1LL << i);
    if (t)
        cout << "No\n";
    else
        cout << "Yes\n";
}