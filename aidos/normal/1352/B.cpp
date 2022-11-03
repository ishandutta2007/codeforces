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
int n, k;
void solve() {
    cin >> n >> k;
    if((n-(k-1) * 2) % 2 == 0 && n >= 2 * k) {
        cout << "YES\n";
        for(int i = 0; i<k; i++) {
            if(i == k-1) cout << n << "\n";
            else {
                n-=2;
                cout << 2 << " ";
            }
        }
        return;
    }
    if(n >= k && (n - (k-1)) % 2 == 1) {
        cout << "YES\n";
        for(int i = 0; i<k; i++) {
            if(i == k-1) cout << n << "\n";
            else {
                n-=1;
                cout << 1 << " ";
            }
        }
        return;
    }
    cout << "NO\n";
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