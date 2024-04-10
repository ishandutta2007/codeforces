#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
#define endl '\n'
const int N = 500087, mod = 998244353;

vector <int> hashh(N);

void solve() {
    int n, m, u, v;
    cin >> n >> m;
    vector <int> aa(n, 0);
    vector <lli> input(n);
    fop (i,0,n) cin >> input[i];
    fop (i,0,m) {
        cin >> u >> v;
        u--; v--;
        aa[v] ^= hashh[u];
    }
    vector <int> a = aa;
    sort(a.begin(), a.end());
    aa.resize(unique(a.begin(), a.end()) - a.begin());
    lli ans = 0;
    lli now[n + 1];
    fop (i,0,n + 1) now[i] = 0;
    fop (i,0,n) {
        if (!aa[i]) continue;
        now[lower_bound(a.begin(), a.end(), aa[i]) - a.begin()] += input[i];
    }
    fop (i,0,n) ans = __gcd(ans, now[i]);
    cout << ans << endl;
}

lli myrand() {
    lli ans = 0, t = 5;
    while (t--) ans = (ans << 10) | (rand() & 1023);
    return ans % mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,0,N) hashh[i] = myrand();
    int t;
    cin >> t;
    while (t--) solve();
}