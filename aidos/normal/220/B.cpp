#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
vector< pair<int, int> > q[maxn];
int ans[maxn];
int t[maxn];
vector<int> g[maxn];
int get(int pos) {
    int res = 0;

    while(pos >= 0) {
        res += t[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}
void upd(int pos, int val) {
    while(pos <= n) {
        t[pos] += val;
        pos |= (pos + 1);
    }
}
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        q[r].emplace_back(make_pair(l, i));
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] <= n) {
            g[a[i]].emplace_back(i);
            
            int x = a[i];
            if(g[x].size() == x) {
                upd(g[x][0], 1);
            } else if(g[x].size() == x + 1) {
                upd(g[x][g[x].size() - x - 1], -2);
                upd(g[x][g[x].size()-x], 1);
            } else if(g[x].size() > x+1) {
                upd(g[x][g[x].size() - x - 2], 1);
                upd(g[x][g[x].size() - x - 1], -2);
                upd(g[x][g[x].size()-x], 1);
            }
        }
        for(pair<int, int> x: q[i]) {
            ans[x.second] = get(n) - get(x.first - 1);
        }
    }
    for(int i = 0; i < k; i++) {
        cout << ans[i] << "\n";
    }
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