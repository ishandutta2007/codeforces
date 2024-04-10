#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, x, k;
int a[maxn];
void solve(){
    cin >> n >> x >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    map<int, int> m, c;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += m[a[i]/x - k];
        m[(a[i] - 1)/x]++;
        c[a[i]]++;
        if(k == 0 && a[i] % x > 0) {
            ans += c[a[i]];
        }
        if(k == 1 && a[i] % x == 0) {
            ans += c[a[i]];
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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