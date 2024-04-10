#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    sort(a, a + n);
    int cnt = 1;
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            ans += cnt;
            cnt++;
        } else {
            cnt=1;
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