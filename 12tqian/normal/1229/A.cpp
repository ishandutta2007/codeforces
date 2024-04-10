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

const int L = 60;

int main() {
    const ll FULL = 1LL << L - 1;
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);

    f0r(i, n) cin >> a[i];
    f0r(i, n) cin >> b[i];

    vector<bool> on(n, true);
    vi better(n);

    f0r(i, n) {
        f0r(j, n) {
            if (i == j) continue;
            if (((a[j] & a[i]) ^ a[i]) > 0) {
                better[i]++;
            }
        }
    }
    int rem = n;
    while (true) {
        vi bad;
        f0r(i, n) {
            if (on[i] && better[i] == rem - 1) {
                bad.pb(i);
            }
        }
        if (sz(bad) == 0) break;
        trav(x, bad) {
            on[x] = false;
            f0r(i, n) {
                if (on[i] && ((a[x] & a[i]) ^ a[i]) > 0) {
                    better[i]--;
                }
            }
        }
        rem -= sz(bad);
    }

    ll ans = 0;

    f0r(i, n) {
        if (on[i]) {
            ans += b[i];
        }
    }

    cout << ans << '\n';

    return 0;
}