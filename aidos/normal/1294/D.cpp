#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld ;
using namespace std;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
int n;
int m;
int cnt[maxn];
void solve() {
    cin >> n >> m;
    int L = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % m]++;
        while(cnt[L % m] > 0) {
            cnt[L % m]--;
            L++;
        }
        cout << L << "\n";
    }
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}