#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;

void solve(){
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'N') cnt++;
    }
    if(cnt == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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