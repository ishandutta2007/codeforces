#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    string s;
    cin >> s;
    int ab = 0, ba = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != s[i-1]) {
            if(s[i] == 'b') ab++;
            else ba++;
        }
    }
    if(ab == ba) {
        cout<<s <<"\n";
        return;
    }
    for(int i = 0; i < s.size(); i++) {
        if(ab > ba && s[i] == 'a') {
            s[i] = 'b';
            break;
        }
        if(ab < ba && s[i] == 'b') {
            s[i] = 'a';
            break;
        }
    }
    cout << s << "\n";
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