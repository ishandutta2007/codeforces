#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)

#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int full = (1 << 30) - 1;

    int n; cin >> n;

    vi a(n);
    f0r(i, n) cin >> a[i];


    vi pre(n), suf(n);

    f0r(i, n) {
        if (i == 0) pre[i] = full ^ a[i];
        else pre[i] = pre[i-1] & (full ^ a[i]);
    }

    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) suf[i] = full ^ a[i];
        else suf[i] = suf[i+1] & (full ^ a[i]);
    }

    pi res = {-1, -1};

    f0r(i, n) {
        int val = a[i];
        val &= (i ? pre[i-1] : full);
        val &= (i != n-1 ? suf[i+1] : full);
        ckmax(res, {val, i});
    }

    swap(a[0], a[res.s]);
    f0r(i, n) cout << a[i] << " ";
    cout << '\n';
    return 0;
}