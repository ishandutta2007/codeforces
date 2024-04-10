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
    cin >> s;
    int s1 = 0, s2 = 0;
    for(char c: s) {
        if(c == '0') s1++;
        else s2++;
    }
    if(s1 == s2) {
        cout << s1 - 1 << "\n";
    } else {
        cout << min(s1, s2) << "\n";
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