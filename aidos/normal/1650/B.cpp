#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    int l, r, a;
    cin >> l >> r >> a;
    int d = r/a;
    int ans = d  + r % a;
    if(d >= 1 && (d-1) * a + a-1 >= l) ans = max(ans, (d-1) + a-1);
    cout << ans << "\n";
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}