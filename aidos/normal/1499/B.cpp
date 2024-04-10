#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    string s;
    cin >> s;
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i < s.size(); i++) {
        a[i] = 0;
        if(s[i] >= s[i-2]) {
            a[i] |= a[i-2];
        }
        if(s[i] >= s[i-1]) {
            a[i] |= a[i-1];
        }
    }
    if(a[s.size()-1] || a[s.size()-2]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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