#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, k;
vector<int> g[maxn];
void solve(){
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        g[x].emplace_back(i);
        cnt = max((int)g[x].size(), cnt);
    }
    int len=inf;
    int pos = 0;
    for(int i = 0; i < maxn; i++) {
        if(g[i].size() == cnt) {
            int r = g[i].back();
            int l = g[i][0];
            if(r - l + 1 < len) {
                pos = l;
                len = r - l + 1;
            }
        }
    }
    cout << pos << " " << pos + len  - 1 << "\n";
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