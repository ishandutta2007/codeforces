#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e7 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int k;
ll ans;
int nxt[maxn][2];
int sz[maxn];
int cur = 0;
void add(int x) {
    int v = 0;
    for(int i = 30; i >= 0; i--) {
        int bit = (x&(1<<i)) > 0;
        if(nxt[v][bit] == 0) {
            nxt[v][bit] = ++cur;
        }
        v = nxt[v][bit];
        sz[v]++;
    }
}

void calc(int x) {
    int v = 0;
    for(int i = 30; i >= 0; i--) {
        int b1 = (x & (1<<i)) > 0;
        int b2 = (k & (1<<i)) > 0;
        if(b2 == 0) {
            if(nxt[v][!b1] > 0) ans += sz[nxt[v][!b1]];
            if(nxt[v][b1] == 0) return;
            v = nxt[v][b1];
        } else {
            if(nxt[v][!b1] == 0) {
                return;
            }
            v = nxt[v][!b1];
        }
    }
    ans+=sz[v];
}
void solve(){
    cin >> n >> k;
    add(0);
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cur ^= x;
        calc(cur);
        add(cur);
    }
    cout << ans << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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