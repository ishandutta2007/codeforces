#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n;
int a[maxn];
void solve(){
    string s;
    cin >> s;
    for(int i = s.size() - 1; i >= 0; i--) {
        char c = (i + 'a');
        if(s[0] == c) {
            s.erase(s.begin());
        } else if(s.back() == c) {
            s.pop_back();
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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