#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int x, y;
void solve() {
    cin >> n >> x >> y;
    for(int z = y; z <= 2500; z++) {
        for(int d = 1; d <= y - x; d++) {
            if(z - (n-1) * d <= 0) continue;
            if((z - y) % d > 0 || (z-y)/d > (n-1)) continue;
            if((z-x) % d > 0||(z-x)/d>n-1) continue;
            for(int i = 0; i < n; i++) {
                cout << z - d * i << " ";
            }
            cout << "\n";
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}