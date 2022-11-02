#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
string s;
int cnt[maxn];
void solve(){
    cin >> n >> k >> s;
    for(int i = 1; i <= n; i++){
        cnt[i] = cnt[i-1] + (s[i-1] - 'a' + 1);
    }
    for(int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        cout << cnt[r] - cnt[l-1] << "\n";
    }
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}