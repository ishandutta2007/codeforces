#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e2 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, m, k;
char a[maxn][maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n-2; i >= 0; i--) {
        for(int j = n-2; j >= 0; j--) {
            if(a[i][j] == '1') {
                if(a[i][j+1] == '1' || a[i+1][j] == '1') {

                }else {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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