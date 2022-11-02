#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
void solve(){
    int x, y;
    string s, t;
    cin >> s >> x >> t >> y;
    if(s.size() + x > t.size() + y) {
        cout << '>' << "\n";
        return;
    }
    if(s.size() + x < t.size() + y) {
        cout << '<' << "\n";
        return;
    }
    for(int i = 0; i < s.size() || i < t.size(); i++) {
        char c, d;
        if(i >= s.size()) c = '0';
        else c = s[i];

        if(i >= t.size()) d = '0';
        else d = t[i];
        if(c == d) continue;
        if(c > d) {
            cout << '>' << "\n";
            return;
        }
        cout << '<' << "\n";
        return;
    }
    cout << '=' << "\n";
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