#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
string s;
void solve(){
    cin>>n >> s;
    string t;
    t += s[0];
    if(n == 1) {
        cout << 0 << "\n";
        return;
    }
    if(s[0] == '0' && s[1] == '0') {
        t += "11";
        t += s[1];
    } else {
        t += s[1];
    }
    for(int i = 2; i < n; i++) {
        if(s[i] == '1') {
            t += s[i];
        } else {
            if(t.back() == '0') t += "11";
            else if(t[t.size() - 2] == '0') t += '1';
            t += s[i];
        }
    }
    cout << t.size() - n  << "\n";
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