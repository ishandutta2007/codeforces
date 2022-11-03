#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    string s, t;
    cin >>n>> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            if(i > 0 && s[i-1] != '?') {
                if(s[i-1] == 'B') s[i] = 'R';
                else s[i] = 'B';
            }
        }
    }
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '?') {
            if(i+1 == n) {
                s[i] = 'R';
            } else {
                if(s[i+1] == 'B') s[i] = 'R';
                else s[i] = 'B';
            }
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