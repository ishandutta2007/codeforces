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
vector<int> g[maxn];
int n;
int a[maxn];
int st[maxn];
void solve() {
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        g[a[i]].push_back(i);
        ans = max(ans, (int)g[a[i]].size());
    }
    for(int i = 0; i < n; i++) {
        int x = a[i];
        st[x]++;
        if(st[x] + st[x] > g[x].size()) continue;
        int pos = g[x][g[x].size() - st[x]];
        while(true) {
            int ok = 0;
            int need = ans + 1 - 2 * st[x];
            for(int j = 1; j <= 200; j++) {
                if(st[j] + need - 1 >= g[j].size()) continue;
                if(g[j][st[j] + need - 1] < pos) ok = 1;
            }
            if(ok) ans++;
            else break;
        }
    }
    cout << ans << "\n";
    for(int i = 1; i <= 200; i++) {
        g[i].clear();
        st[i] = 0;
    }
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