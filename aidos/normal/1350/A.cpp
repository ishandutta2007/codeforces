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
int n, m, k;
int a[maxn];
void solve() {
    cin >> n >> k;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            cout << n + i + 2 * (k-1) << "\n";
            return;
        }
    }
    cout << n * 2 + 2 * (k-1) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}