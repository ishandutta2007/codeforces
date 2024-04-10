#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
string s;
int cnt[maxn];

void solve(){
    ll a, b;
    cin >> a >> b;
    if(a >= 3 * b) {
        cout << b << "\n";
        return;
    }
    if(b >= 3 * a) {
        cout << a << "\n";
        return;
    }
    cout << (a + b)/4 << "\n";
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