#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n;
    int x;
    ll s = 0;
    ll g = 1;
    for(int i = 0; i < n; i++) {
        cin >> x;
        s += x;
        if(s < i) g = 0;
        s -= i;
    }
    if(g) cout << "YES\n";
    else cout << "NO\n";
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