#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int b[maxn];

void solve() {
    string s;
    cin >> n >> k >> s;
    int pos = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '.') continue;
        if(pos==-1) {
            a[i] = 1;
        } else {
            a[i] = 1e9;
            for(int j = 0; j < i; j++) {
                if(s[j] == '*' && i - j <= k) a[i] = min(a[i], a[j] + 1);
            }
        }
        pos = i;
    }
    cout << a[pos] << "\n";
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