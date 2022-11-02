#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; ) {
        if(a[i] == 0) {
            i++;
            continue;
        }
        while(i < n && (a[i] == 1 || a[i + 1] == 1)) {
            i++;
            ans++;
        }
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