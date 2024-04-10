#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n >> k;
    int s = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    for(int i = 0; i < k; i++) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            s -= a[x];
            a[x] = 1-a[x];
            s += a[x];
        } else {
            if(s >= x) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}