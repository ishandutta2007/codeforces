#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
ll a[maxn];
int pref[maxn];
int t[3][maxn];
int get(int c, int pos) {
    int sum = 0;
    while(pos >= 0) {
        sum += t[c][pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return sum;
}
void add(int c, int pos) {
    while(pos <= 2 * n) {
        t[c][pos]++;
        pos |= (pos + 1);
    }
}
void solve() {
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1];
        if(s[i-1] == '+') {
            pref[i]--;
        } else {
            pref[i]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i <= 2 * n; i++) {
        t[0][i] = t[1][i] = t[2][i] = 0;
    }
    add(0, n);
    for(int i = 1; i <= n; i++) {
        int c = pref[i] % 3;
        if(c < 0) c += 3;
        ans += get(c, pref[i] + n);
        add(c, pref[i] + n);
    }
    cout << ans << "\n";
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