#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int p[maxn];
ll suma[maxn];
ll sumb[maxn];
string s;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];
    cin >> s;
    for(int i = 1; i <= n; i++) {
        if(s[i-1] == 'A') {
            suma[i] = suma[i-1] + p[i];
            sumb[i] = sumb[i-1];
        } else {
            suma[i] = suma[i-1];
            sumb[i] = sumb[i-1] + p[i];
        }
    }
    ll ans = sumb[n];
    for(int i = 1; i <= n; i++) {
        ans = max(ans, sumb[n] - sumb[i] + suma[i]);
        ans = max(ans, suma[n]-suma[i-1] + sumb[i-1]);
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
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