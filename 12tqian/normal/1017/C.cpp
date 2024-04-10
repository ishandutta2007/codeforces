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
typedef double db;

template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }

int lis(vi v) {
    int n = sz(v);
    vi res(n);
    f0r(i, n) {
        res[i] = 1;
        f0r(j, i) {
            if (v[j] < v[i]) 
                ckmax(res[i], res[j]+1);
        }
    }
    int mx = 0;
    f0r(i, n) ckmax(mx, res[i]);
    return mx;
}
const int INF = 1e9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    pi best = {INF, INF};
    f1r(k, 1, n+1) { // length of lis
        int mx = (n+k-1)/k;
        ckmin(best, {mx+k, k});
    }
    int k = best.s;
    int sz = (n+k-1)/k;
    vi p(n);
    iota(all(p), 1);
    int i1 = 0;
    int i2 = sz-1;

    while (i1 < n) {
        ckmin(i2, n-1);
        reverse(p.begin() + i1, p.begin() + i2 + 1);
        i1 += sz;
        i2 += sz;
    }

    trav(t, p) cout << t << " ";
    cout << '\n';
    return 0;
}