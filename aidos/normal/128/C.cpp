#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m, k;

int a[maxn];
ll get(int x, int y) {
    if(x<y) return 0;
    ll res = 1;
    for(int i = 1; i <= y; i++) {
        a[i] = i;
    }
    for(int i = x - y + 1; i <= x; i++) {
        int d = i;
        for(int j = 1; j <= y; j++) {
            int g = __gcd(d, a[j]);
            d /= g;
            a[j] /= g;
        }
        res = (res*d) % mod;
    }
    return res;
}
void solve() {
    cin >> n >> m >> k;
    ll a = (get(n-2, 2 * k) + get(n-2, 2 * k-1)) % mod;
    ll b= (get(m-2, 2 * k) + get(m-2, 2 * k-1)) % mod;
    cout << a * b % mod << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}