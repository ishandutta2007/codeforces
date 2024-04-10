#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n;
int u[maxn];
void solve(){
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        for(int j = l; j < r; j++) {
            ans -= u[j];
            u[j] = (i == 0);
            ans += u[j];
        }
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