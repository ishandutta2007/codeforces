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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17, K = 3e6;

vector <int> build_sa (vector <int> s) {
    int n = s.size();
    vector <int> r(n), sa(n);
    iota(all(sa), 0);
    sort(all(sa), [&](int i, int j) {return s[i] < s[j];});
    r[sa[0]] = 0;
    for (int i = 1; i < n; ++i) {
        if (s[sa[i - 1]] == s[sa[i]]) r[sa[i]] = r[sa[i - 1]];
        else r[sa[i]] = r[sa[i - 1]] + 1;
    }
    for (int k = 0; (1 << k) < n; k++) {
        vector <int> nsa(n), nr(n);
        for (int i = 0; i < n; ++i) nsa[i] = (sa[i] - (1 << k) + n) % n;
        vector <int> cnt(n, 0);
        for (int i = 0; i < n; ++i) cnt[r[i]]++;
        for (int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) sa[--cnt[r[nsa[i]]]] = nsa[i];
        nr[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            int cnt = 0;
            if (r[sa[i - 1]] != r[sa[i]]) cnt = 1;
            if (r[(sa[i - 1] + (1 << k)) % n] != r[(sa[i] + (1 << k)) % n]) cnt = 1;
            nr[sa[i]] = nr[sa[i - 1]] + cnt;
        }
        swap(r, nr);
    }
    return sa;
}

vector <int> build_he(vector <int> s) {
    int n = s.size();
    vector <int> sa = build_sa(s), r(n), h(n - 1);
    for (int i = 0; i < n; ++i) r[sa[i]] = i;
    for (int i = 0, k = 0; i < n - 1; ++i, k = max(k - 1, 0)) {
        while (s[i + k] == s[sa[r[i] - 1] + k]) k++;
        h[r[i] - 1] = k;
    }
    return h;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a, s, c(n), tmp;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        for (char c : t) s.pb(c - 'a' + n), a.pb(i);
        s.pb(n - i - 1);
        a.pb(-1);
        int cur = t.length();
        while (tmp.size() < s.size()) tmp.pb(cur--);
    }
    for (int i = 0; i < n; ++i) cin >> c[i];
    vector <int> h = build_he(s), sa = build_sa(s);
    vector <lli> l(h.size()), r(h.size()), pre(sa.size() + 1, 0);
    for (int i = 0; i < sa.size(); ++i) {
        if (a[sa[i]] != -1) {
            pre[i + 1] = pre[i] + c[a[sa[i]]];
        } else {
            pre[i] = pre[i];
        }
    }
    stack <int> stk;
    for (int i = 0; i < h.size(); ++i) {
        while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
        l[i] = stk.size() ? pre[i + 2] - pre[stk.top() + 1] : pre[i + 2];
        stk.push(i);
    }
    while (stk.size()) stk.pop();
    for (int i = h.size() - 1; ~i; --i) {
        while (stk.size() && h[stk.top()] >= h[i]) stk.pop();
        r[i] = stk.size() ? pre[stk.top() + 1] - pre[i] : pre[sa.size()] - pre[i];
        stk.push(i);
    }
    lli ans = 0;
    for (int i = 0; i < h.size(); ++i) {
        ans = max(ans, (l[i] + r[i] - pre[i + 2] + pre[i]) * h[i]);
    }
    for (int i = 0; i < sa.size(); ++i) {
        if (h[i] != tmp[sa[i]] && (!i || h[i - 1] != tmp[sa[i]]) && a[sa[i]] != -1) {
            ans = max(ans, 1ll * c[a[sa[i]]] * tmp[sa[i]]);
        }
    }
    cout << ans << endl;
}