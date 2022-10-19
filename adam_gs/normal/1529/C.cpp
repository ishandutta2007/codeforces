#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7;
vector<int>V[LIM];
ll dp[LIM][2], T[LIM][2];
void DFS(int x, int o) {
        for(auto i : V[x]) if(i!=o) {
                DFS(i, x);
                dp[x][0]+=max(dp[i][0]+abs(T[x][0]-T[i][0]), dp[i][1]+abs(T[x][0]-T[i][1]));
                dp[x][1]+=max(dp[i][0]+abs(T[x][1]-T[i][0]), dp[i][1]+abs(T[x][1]-T[i][1]));
        }
}
void solve() {
        int n;
        cin >> n;
        rep(i, n) {
                V[i].clear();
                dp[i][0]=dp[i][1]=0;
                cin >> T[i][0] >> T[i][1];
        }
        rep(i, n-1) {
                int a, b;
                cin >> a >> b; --a; --b;
                V[a].pb(b);
                V[b].pb(a);
        }
        DFS(0, 0);
        cout << max(dp[0][0], dp[0][1]) << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _;
        cin >> _;
        while(_--) solve();
}