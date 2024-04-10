#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    cin >>n;
    int ans = maxn;
    int ok = 0;
    for(int i = 1; i <= 2000; i++) {
        if(ok) {
            ans = min(ans,i);
            break;
        }
        if(i * (i + 1)/2 >= n) {
            if(i * (i + 1)/2 != n+1) ans = min(ans, i);
            ok = 1;
        }
    }
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