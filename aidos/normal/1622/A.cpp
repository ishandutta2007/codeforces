#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
char a[maxn];
int cnt[maxn];
int c[maxn];
int get(int a, int b, int c) {
    if(a == b + c) return 1;
    if(b == c && a % 2 == 0) return 1;
    return 0;
}
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(get(a, b, c) || get(b, a, c) || get(c, a, b)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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