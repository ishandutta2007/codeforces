#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
string s;
int n, x, y;
int a[maxn];
int d[maxn];
pair<int, int> b[maxn];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        //cin >> a[i];
    }
    cin >> x >> y;
    if(x==y) {
        cout << 0 << "\n";
        return;
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;
    int len = (x-y);
    for(int i = 1; i <= len; i++) {
        d[i] = i - 1;
    }
    for(int i = 0; i < n; i++) {
        ll c = (y + a[i] - 1ll)/a[i] * a[i];
        b[i] = make_pair(c, a[i]);
    }
    sort(b, b + n);
    int cnt = 0;
    while(x > y) {
        int c = x - 1;
        for(int i = 0; i < n && b[i].first < x; i++) {
            c = min(c, x-x % b[i].second);
        }
        cnt++;
        x = c;
    }
    cout << cnt << "\n";
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}