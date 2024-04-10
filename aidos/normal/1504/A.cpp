#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    string s;
    cin >> s;
    string t = s+"a";
    for(int i = 0; i < t.size(); i++) {
        if(t[i] != t[t.size() - i - 1]) {
            cout << "YES\n";
            cout << t << "\n";
            return;
        }
    }
    t = "a" + s;
    for(int i = 0; i < t.size(); i++) {
        if(t[i] != t[t.size() - i - 1]) {
            cout << "YES\n";
            cout << t << "\n";
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