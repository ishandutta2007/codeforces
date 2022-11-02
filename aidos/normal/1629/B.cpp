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
    int l, r, k;
    cin >> l >> r >> k;
    if(r == 1) {
        cout << "NO\n";
        return;
    }
    if(l == r) {
        cout << "YES\n";
        return;
    }
    int cnt = (r+1)/2 - l/2;
    if(cnt <= k) {
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