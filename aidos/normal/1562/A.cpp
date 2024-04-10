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
    int l, r;
    cin >> l >> r;
    if(r <= l + l - 1){
        cout << r % l << "\n";
    } else {
        int c = r/2;
        cout << max({r % l, r % c, r % (c + 1)}) << "\n";
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