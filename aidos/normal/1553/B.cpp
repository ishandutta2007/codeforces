#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int b[maxn];

void solve() {
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    for(int i = 0; i < s.size(); i++) {
        int j = 0;
        while(i + j < s.size() && j < t.size() && s[i + j] == t[j]) {
            j++;
            int ok = 1;
            for(int k = j; k < t.size(); k++) {
                if(i + j - 2 - (k - j) < 0) {
                    ok = 0;
                    break;
                }
                if(t[k] != s[i+j-2-(k-j)]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                cout << "YES\n";
                return;
            }
        }
        if(j == t.size()) {
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