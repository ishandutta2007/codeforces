#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
vector<int> g[maxn];
int a[maxn];
int ans[maxn];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        g[x % m].emplace_back(i);
    }
    vector<int> z;
    ll cur = 0;
    for(int i = 0; i < 2 * m; i++) {
        int d = i % m;
        while(g[d].size() > n/m) {
            z.emplace_back(g[d].back());
            g[d].pop_back();
        }
        while(g[d].size() < n/m) {
            if(z.size()==0) break;
            int ind = z.back();
            z.pop_back();
            cur += i - a[ind] % m;
            a[ind] += i - a[ind] % m;
            g[d].emplace_back(ind);
        }
    }
    cout << cur << "\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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