#pragma GCC optmize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long

typedef long long ll;

int k, A, B;
vector <int> a;

int go(int l, int r) {
    if (lower_bound(all(a), r) - lower_bound(all(a), l) == 0)
        return A;
    if (r - l == 1)
        return B * (lower_bound(all(a), r) - lower_bound(all(a), l)) * (r - l);
    int m = (l + r) / 2;
    return min(B * (lower_bound(all(a), r) - lower_bound(all(a), l)) * (r - l), go(l, m) + go(m, r));
}
main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> k >> A >> B;
    a.resize(k);
    forn (i, 0, k)
        cin >> a[i];
    sort(all(a));
    cout << go(1, (1 << n) + 1);
    return 0;
}