#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
ll a[maxn];
ll b[maxn];
void solve(){
    cin >> n >> m;
    ll s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    sort(a, a + n);
    ll last = 0;

    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        b[i] = min(last + 1, a[i]);
        last = b[i];
        cnt++;
    }
    cnt += a[n-1]-last;
    cout << s - cnt << "\n";
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