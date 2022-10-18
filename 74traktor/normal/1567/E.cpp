#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 2e5 + 5;
int a[maxn];
int pref[(1 << 19)], suff[(1 << 19)];
ll ans[(1 << 19)];
ll answer;
int len, last;

inline ll get(int Len) {
    return (ll)Len * (ll)(Len + 1) / 2;
}

inline void merge(int i, int l, int m, int r) {
    pref[i] = pref[2 * i + 1];
    suff[i] = suff[2 * i + 2];
    ans[i] = ans[2 * i + 1] + ans[2 * i + 2];
    if (pref[i] == m - l) {
        if (a[m - 1] <= a[m]) {
            pref[i] += pref[2 * i + 2];
            if (pref[i] != r - l) {
                ans[i] += get(pref[2 * i + 1]) + (ll)(m - l) * (ll)pref[2 * i + 2];
            }
        }
        else {
            ans[i] += get(pref[i]);
        }
    }
    if (suff[i] == r - m) {
        if (a[m - 1] <= a[m]) {
            suff[i] += suff[2 * i + 1];
            if (suff[i] != r - l) {
                ans[i] += get(suff[2 * i + 2]) + (ll)(r - m) * (ll)suff[2 * i + 1];
            }
        }
        else {
            ans[i] += get(suff[i]);
        }
    }
    if (a[m - 1] <= a[m] && suff[2 * i + 1] != m - l && pref[2 * i + 2] != r - m) {
        ans[i] += (ll)suff[2 * i + 1] * (ll)pref[2 * i + 2];
    }
}

void build(int i, int l, int r) {
    if (r - l == 1) {
        pref[i] = 1, suff[i] = 1;
    }
    else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        merge(i, l, m, r);
    }
}

void update(int i, int l, int r, int lq, int x) {
    if (r - l == 1) {
        a[lq] = x;
    }
    else {
        int m = (r + l) / 2;
        if (lq < m) update(2 * i + 1, l, m, lq, x);
        else update(2 * i + 2, m, r, lq, x);
        merge(i, l, m, r);
    }
}

void get(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        answer += ans[i];
        if (last <= a[l]) {
            if (pref[i] == r - l) {
                len += (r - l);
            }
            else {
                answer += get(len) + (ll)len * (ll)pref[i];
                len = suff[i];
                answer -= get(len);
            }
        }
        else {
            answer += get(len);
            len = suff[i];
            if (len != r - l) answer -= get(len);
        }
        last = a[r - 1];
        return;
    }
    int m = (r + l) / 2;
    get(2 * i + 1, l, m, lq, rq);
    get(2 * i + 2, m, r, lq, rq);
}

main() {
#ifdef karpovich
    freopen("input.txt", "r", stdin);
#endif // karpovich
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, t, l, r;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(0, 1, n + 1);
    for (int i = 1; i <= q; ++i) {
        cin >> t >> l >> r;
        if (t == 1) update(0, 1, n + 1, l, r);
        else {
            answer = 0;
            len = 0, last = -1;
            get(0, 1, n + 1, l, r + 1);
            answer += get(len);
            cout << answer << '\n';
        }
    }
    return 0;
}