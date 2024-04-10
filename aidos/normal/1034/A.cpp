#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1.5e7 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m, k;
int a[maxn];
int b[300300];
int pr[maxn];
void solve() {
    cin >> n;
    int g = 0;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        b[i] = x;
        g = __gcd(x, g);
    }


    int ans = n;
    for(int i = 2; i * i < maxn; i++) {
        int cnt = 0;
        if(pr[i] != 0) continue;
        for(ll j = i * i; j < maxn; j+=i) {
            pr[j] = i;
        }
    }
    for(int i = 2; i < maxn; i++) if(pr[i] == 0) pr[i] = i;
    for(int i = 0; i < n; i++) {
        int x = b[i]/g;
        while(x > 1) {
            int cur = pr[x];
            while(x % cur == 0) x/=cur;
            a[cur]++;
        }
    }
    for(int i = 2; i < maxn; i++) ans = min(ans, n-a[i]);
    if(ans == n) ans = -1;
    cout << ans << "\n";
}


int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}