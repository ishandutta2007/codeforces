#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int c, d, n, m, k;
void solve() {
    cin >> c >> d >> n >> m >> k;
    int ans = inf;
    for(int i = 0; i <= 1000; i++) {
        int j = max(n * m - n * i - k, 0); 
        ans = min(ans, c * i + j * d);
        
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
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}