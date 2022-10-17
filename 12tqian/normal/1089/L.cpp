#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++) 
#define f0r(i, a) f1r(i, 0, a)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vi a(n);
    f0r(i, n) cin >> a[i], a[i]--;
    vl b(n);
    f0r(i, n) cin >> b[i];
    vector<vl> use(k);
    f0r(i, n) {
        use[a[i]].eb(b[i]);
    }
    ll ans = 0;
    multiset<ll> bad;
    int need = 0;
    f0r(i, k) {
        if (sz(use[i]) == 0) need++;
        sort(all(use[i]));
        reverse(all(use[i]));
        while (sz(use[i])>1) {
            bad.insert(use[i].back());
            use[i].pop_back();
        }
    }
    while (need--) {
        ans += *bad.begin();
        bad.erase(bad.begin());
    }
    cout << ans << '\n';

    return 0;
}