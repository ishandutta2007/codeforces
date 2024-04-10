#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int b[maxn];

void solve() {
    string s, t;
    cin >> n >> s;
    int last = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(last != 2) {
                t += '1';
                last = 2;
            } else {
                t += '0';
                last = 1;
            }
        } else if(last != 1) {
            t += '1';
            last = 1;
        } else {
            t += '0';
            last = 0;
        }
    }
    cout << t << "\n";
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