#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int b[maxn];

void solve() {
    cin >> n;
    if(n >= 1) cout << 9;
    if(n >= 2) cout << 8;
    if(n >= 3) cout << 9;
    for(int i = 0; i < n - 3; i++) cout << i % 10;
    cout << "\n";
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