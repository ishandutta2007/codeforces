#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    int r, g, b, w;
    cin >> r >> g >> b >> w;
    for(int it=0; it < 10; it++) {
        if (r % 2 + g % 2 + b % 2 + w % 2 <= 1) {
            cout << "YES\n";
            return;
        }
        if (r > 0 && g > 0 && b > 0) {
            r--;
            g--;
            b--;
            w += 3;
        }
    }
    cout << "NO\n";
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