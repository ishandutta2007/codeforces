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
    }
    ll s = 0, t = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < 0) {
            a[i] *= -1;
            if(s > a[i]) {
                s -= a[i];
            } else {
                t += a[i] - s;
                s  = 0;
            }
        } else {
            s += a[i];
        }
    }
    cout << t << "\n";
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