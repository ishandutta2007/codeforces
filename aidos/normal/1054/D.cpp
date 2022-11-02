#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
int b[maxn];
void solve(){
    cin >> n >> k;
    k = (1<<k) - 1;
    map<int, int> cnt;
    int cur=0;
    cnt[cur]++;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cur ^= a[i];
        cnt[min(cur, cur ^ k)]++;
    }
    ll ans = n * (n + 1ll)/2;
    for(pii x: cnt) {
        ll A = x.second/2;
        ll B = x.second - A;
        ans -= A * (A-1)/2;
        ans -= B * (B-1)/2;
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