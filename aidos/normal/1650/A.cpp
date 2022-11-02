#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];

void solve(){
    string s;
    char c;
    cin >> s >> c;
    if(s.size() % 2 == 0) {
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < s.size(); i+=2) {
        if(s[i] == c) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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