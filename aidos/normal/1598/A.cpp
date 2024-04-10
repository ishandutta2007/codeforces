#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
void solve(){
    string s, t;
    cin >> n >> s >> t;
    a[0] = 1;
    for(int i = 1; i < n; i++) {
        a[i] = 0;
        b[i] = 0;
        if(s[i] == '0' && (a[i-1] || b[i-1])) a[i] = 1;
        if(t[i] == '0' && (a[i-1] || b[i-1])) b[i] = 1;
    }
    if(b[n-1]) {
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