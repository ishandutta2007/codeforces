#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 1000001, logN = 17;

vector <int> build_sa(string s) {
    s += '$';
    int n = s.length();
    vector <int> r(n), sa(n);
    iota(all(sa), 0);
    sort(all(sa), [&](int i, int j) {
        return s[i] < s[j];
    });
    r[sa[0]] = 0;
    for (int i = 1; i < n; ++i) {
        if (s[sa[i]] == s[sa[i - 1]]) r[sa[i]] = r[sa[i - 1]];
        else r[sa[i]] = r[sa[i - 1]] + 1;
    }
    for (int k = 0; 1 << k < n; ++k) {
        vector <int> nr(n), nsa(n), cnt(n);
        for (int i = 0; i < n; ++i) nsa[i] = (sa[i] - (1 << k) + n) % n;
        for (int i = 0; i < n; ++i) cnt[r[i]]++;
        for (int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; ~i; --i) sa[--cnt[r[nsa[i]]]] = nsa[i];
        nr[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            int re = 0;
            if (r[sa[i - 1]] != r[sa[i]]) re = 1;
            if (r[(sa[i - 1] + (1 << k)) % n] != r[(sa[i] + (1 << k)) % n]) re = 1;
            nr[sa[i]] = nr[sa[i - 1]] + re;
        }
        swap(nr, r);
    }
    return sa;
}

vector <int> build_hei(string s) {
    int n = s.length();
    vector <int> sa = build_sa(s), r(n + 1), h(n);
    for (int i = 0; i <= n; ++i) r[sa[i]] = i;
    for (int i = 0, k = 0; i < n; ++i, k = max(k - 1, 0)) {
        while (s[i + k] == s[sa[r[i] - 1] + k]) k++;
        h[r[i] - 1] = k;
    }
    return h;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    reverse(all(s));
    reverse(all(t));
    vector <int> h = build_hei(s), sa = build_sa(s), l(n), r(n);
    lli ans = n;
    for (int i = 0; i < n; ++i) {
        if (t[i] == '1') ans--;
        else break;
    }
    vector <int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + (t[sa[i + 1]] == '1' ? 0 : 1);
    stack <int> stk;
    for (int i = 0; i < n; ++i) {
        while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
        l[i] = stk.size() ? pre[i] - pre[stk.top()] : pre[i + 1];
        stk.push(i);
    }
    while (stk.size()) stk.pop();
    for (int i = n - 1; ~i; --i) {
        while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
        r[i] = stk.size() ? pre[stk.top()] - pre[i] : pre[n] - pre[i];
        stk.push(i);
    }
    for (int i = 0; i < n; ++i) {
        ans = max(ans, 1ll * h[i] * (l[i] + r[i]));
    }
    cout << ans << endl;
}