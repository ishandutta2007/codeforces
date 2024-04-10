#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
string s;
int cnt[maxn];
int get(int x) {
    return (int)(pow(x, 1.0/3.0) + 1e-9);
}
void solve(){
    cin >> n;
    int ans=(int)sqrt(n) + get(n) - get(sqrt(n));
    cout << ans << "\n";
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