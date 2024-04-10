#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
void solve(){
    cin >> n >> k;
    vector<string> c(n, string(n, '.'));
    int x = 0;
    for(int i = 0; i < k; i++) {
        if(x >= n) {
            cout << -1 << "\n";
            return;
        }
        c[x][x] = 'R';
        x += 2;
    }
    for(auto d: c) cout << d << "\n";
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