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


pair<db, int> set_equal(pair<db, int> x, pair<db, int> y) {
    return {(x.f * x.s + y.f * y.s) / (x.s + y.s), 
                x.s + y.s};
};

int main() {
#ifndef LOCAL
    cout << fixed << setprecision(10);
#endif

    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    vector<ll> a(n);

    f0r(i, n) cin >> a[i];

    deque<pair<db, int>> bef;
    deque<pair<db, int>> aft;

    f0r(i, n) aft.emplace_back(a[i], 1);

    while (sz(aft)) {
        auto cur = aft.front();
        aft.pop_front();

        while (true) {
            if (sz(bef) && bef.back().f >= cur.f) {
                cur = set_equal(cur, bef.back());
                bef.pop_back();
            } else if (sz(aft) && cur.f >= aft[0].f) {
                cur = set_equal(cur, aft[0]);
                aft.pop_front();
            } else {
                break;
            }
        }

        bef.push_back(cur);
    }


    trav(t, bef) {
        f0r(i, t.s) {
            cout << t.f << " ";
        }
    }

    return 0;
}