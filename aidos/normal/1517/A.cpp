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
    ll n;
    cin >> n;
    if(n % 2050 != 0) {
        cout << -1 << "\n";
        return;
    }
    int s=0;
    n /= 2050;
    while(n > 0) {
        s += n % 10;
        n /= 10;
    }
    cout << s << "\n";
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