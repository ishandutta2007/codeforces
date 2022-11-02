#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n;
    int d = sqrt(n + 0.5);
    if(d * d == n) {
        cout << d << " " << 1 << "\n";
        return;
    }
    n -= d * d;
    d++;
    if(n <= d) {
        cout << n << " " << d << "\n";
    } else{
        cout << d << " " << (d - (n-d)) << "\n";
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}