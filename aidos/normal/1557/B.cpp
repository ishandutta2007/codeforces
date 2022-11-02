#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(b, b + n, a[i]) - b;
    }
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i-1] + 1)ans++;
    }
    if(ans <= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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