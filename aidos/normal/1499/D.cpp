#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 2e7 + 123;
const int mod = 1e9 + 9;
string s;
int c, d, x;
int dp[maxn];
int D[maxn];
bool is_prime(int x) {
    return D[x] == x;
}
void precalc() {
    for(int i = 2; i < maxn; i++) D[i] = i;
    for(int i = 2; i * i < maxn; i++) {
        if(D[i] == i){
            for(int j = i *i; j < maxn; j += i) {
                D[j] = i;
            }
        }
    }
}
ll calc(int y) {
    if((y + d) % c != 0) return 0;
    y = (y + d)/c;
    if(dp[y] != 0) return dp[y];
    int Y = y;
    int res = 1;
    for(int i = D[y]; y > 1; i = D[y]) {
        while(y % i == 0) y/=i;
        res *= 2;
    }
    return dp[Y] = res;
}
void solve() {
    cin >> c >> d >> x;
    ll ans = 0;
    for(int i = 1; i*i<=x; i++) {
        if(x % i == 0) {
            ans += calc(i);
            if(i * i != x) ans += calc(x/i);
        }
    }
    cout << ans << "\n";
}

int main() {
    precalc();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}
//