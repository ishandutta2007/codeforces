#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, k;

int p[maxn];
int s[maxn];
int v[maxn];
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 2; i <= n; i++) {
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        v[i] = inf;
    }
    for(int i = n; i > 1; i--) {
        if(s[i] != -1) {
            int j = p[i];
            if(s[i] < s[p[j]]) {
                cout << -1 << "\n";
                return;
            }
            v[j] = min(v[j], s[i] - s[p[j]]);
        }
    }
    ll ans = s[1];
    for(int i = 2; i <= n; i++) {
        if(s[i] == -1) {
            if(v[i] == inf) {
                v[i] = 0;
            }
            s[i] = s[p[i]] + v[i];
        }
        //continue;
        ans += s[i] - s[p[i]];
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}