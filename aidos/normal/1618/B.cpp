#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    cin >> n;
    string s="";
    cin >> s;
    int ok = 0;
    for(int i = 1; i < n-2; i++) {
        string t;
        cin >> t;
        if(t[0] == s.back()) {
            s += t[1];
        } else {
            ok = 1;
            s += t;
        }
    }
    if(!ok) {
        s += 'a';
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