#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;
pair<int, int> u[maxn];
int used[maxn];
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        if(u[l].first <= r) {
            u[l] = make_pair(r, i);
        }
    }
    for(int i = 1; i <= n; ) {
        if(u[i].first==0) {
            i++;
            continue;
        }
        used[u[i].second] = 1;
        int j = i + u[i].first;
        i++;
        pair<int, int> mx = make_pair(0, 0);
        while(i < j) {
            int len = i+u[i].first - j;
            mx = max(mx, make_pair(len, u[i].second));
            i++;
        }
        u[i] = max(u[i], mx);
    }
    vector<int> ans;
    for(int i = 1; i <= m; i++) {
        if(!used[i]) ans.emplace_back(i);
    }
    cout << ans.size() << "\n";

    for(int id: ans) cout << id << " ";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
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