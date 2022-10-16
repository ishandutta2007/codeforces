#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve_case() {
    int n; cin >> n;
    vi a(n);
    f0r(i, n) cin >> a[i];
    vector<deque<int>> dq(n);
    set<int> ord;
    f0r(i, n) ord.insert(i);
    f0r(i, n) dq[i].pb(i);
    auto merge = [&](int x, int y) -> int {
        int rem;
        if (sz(dq[x]) < sz(dq[y])) {
            reverse(all(dq[x]));
            each(e, dq[x]) dq[y].push_front(e);
            dq[x].clear();
            rem = x;
        } else {    
            each(e, dq[y]) dq[x].pb(e);
            dq[y].clear();
            rem = y;
        }   
        return rem;
    };
    vi ans;
    while (sz(ord)) {
        auto it = ord.begin();
        bool change = false;
        while (it != ord.end()) {
        // cout << "----------" << endl;
        // each(x, ord) {
        //     each(y, dq[x]) cout << y + 1 << " ";
        //     cout << " | ";
        // }
        // cout << endl;
            auto go = next(it);
            if (go == ord.end()) go = ord.begin();
            int i1 = *it;
            int i2 = *go;
            auto& d1 = dq[i1];
            auto& d2 = dq[i2];
            if (sz(d1) && sz(d2) && __gcd(a[d1.back()], a[d2.front()]) == 1) {
                change = true;
                // cout << dq[i2].front() + 1 << " REM " << endl;
                ans.pb(dq[i2].front());
                dq[i2].pop_front();
                it = next(it);
                if (sz(dq[i2])) {
                    continue;
                }
                if (it == ord.end()) {
                    break;
                }
                it = next(it);
            } else {
                ord.erase(ord.find(merge(i1, i2)));
                if (ord.count(i1)) it = ord.find(i1);
                else it = ord.find(i2);
            }
        }
        if (!change)  {
            break;
        }
    }
    cout << sz(ans) << " ";
    each(x, ans) cout << x + 1 << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) solve_case();
    return 0;
}