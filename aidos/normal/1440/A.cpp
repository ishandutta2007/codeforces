#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    int c0, c1, h;
    string s;
    int ans = 0;
    cin >> n >> c0 >> c1 >> h >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            ans += min(c0, c1 + h);
        } else {
            ans += min(c1, c0 + h);
        }
    }
    cout << ans << "\n";
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