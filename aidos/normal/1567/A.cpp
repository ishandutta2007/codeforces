#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
string s;
int cnt[maxn];
void solve(){
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'U') s[i] = 'D';
        else if(s[i] == 'D') s[i] = 'U';
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