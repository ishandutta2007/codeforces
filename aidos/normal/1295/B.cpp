#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
ll x;
char s[maxn];
int a[maxn];
void solve() {
    scanf("%d%lld%s", &n, &x, s);
    for(int i = 1; i <= n; i++) {
        if(s[i-1] == '0')
            a[i] = a[i-1] + 1;
        else
            a[i] = a[i-1] - 1;
    }
    int bal = a[n];
    ll ans = 0;
    for(int i=0; i < n; i++) {

        if(bal == 0) {
            if(x == a[i]) {
                cout << -1 << "\n";
                return;
            }
        } else {
            if((x-a[i]) % bal == 0 && (x-a[i]) / bal >= 0) ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}


#pragma clang diagnostic pop