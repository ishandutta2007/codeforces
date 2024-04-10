#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int b[maxn];

void solve() {
    ll s=0;
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> a[i];
        s += n - a[i];
    }
    sort(a, a + k);
    int ans = 0;
    for(int i = 0; i < k; i++) {
        s -= n - a[i];
        if(a[i] - 1 >= s) {
            cout << k - i << "\n";
            return;
        }
    }
    cout << 0 << "\n";
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