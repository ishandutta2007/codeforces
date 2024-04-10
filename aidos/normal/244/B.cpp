#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
void solve() {
    cin >> n;
    set<int> ans;
    if(n == (int)1e9) {
        ans.insert(n);
    }
    for(int len = 1; len <= 9; len++) {
        for(int mask = 0; mask<(1<<len); mask++) {
            int a = 0, b = 0;
            for(int i  = 0; i < len; i++) {
                a *= 10;
                b *= 10;
                if(mask & (1<<i)) {
                    a++;
                }else b++;
            }
            for(int x = 0; x < 10; x++) {
                for(int y = 0; y < 10; y++) {
                    int cur = a * x + b * y;
                    if(cur > 0 && cur <= n) ans.insert(cur);
                }
            }
        }
    }
    cout << ans.size() << "\n";
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