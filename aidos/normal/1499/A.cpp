#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    if((k1 + k2)/2 >= w && (n-k1 + n - k2)/2 >= b) {
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