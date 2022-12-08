#include <bits/stdc++.h>

using namespace std;

#define pb push_back

using ull = unsigned long long;
const int maxn = 2e5 + 5;
vector<int> G[maxn], bst[maxn];
int n, m;
int x[maxn], y[maxn];
ull a, b, c;
ull ans = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> a >> b >> c;
    for(ull i = 0; i < n; i++) {
        ans += (n - i - 1) * (n - i - 2) / 2 * a * i;
        ans += i * (n - i - 1) * b * i;
        ans += (i - 1) * i / 2 * c * i;
    }
    for(int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        if(x[i] > y[i])   swap(x[i], y[i]);
        ull u = x[i], v = y[i];
        bst[u].pb(v);
        bst[v].pb(u);
        G[u].pb(v);
        ans -= u * (u - 1) / 2 * a + u * (b * u + c * v);
        ans -= (v - u - 1) * (u + v) / 2 * b + (v - u - 1) * (a * u + c * v);
        ans -= (n - v - 1) * (n + v) / 2 * c + (n - v - 1) * (a * u + b * v);
    }

    for(int i = 0; i < n; i++) {
        sort(bst[i].begin(), bst[i].end());;
        ull sz = bst[i].size(), cnt = 0;
        for(int j = 0; j < bst[i].size(); j++) {
            int v = bst[i][j];
            if(v < i) {
                ans += a * v * (sz - j - 1) + b * v * j;
                cnt++;
            } else
                ans += b * v * (sz - j - 1) + c * v * j;
        }
        ans += cnt * (cnt - 1) / 2 * c * i  + b * i * cnt * (sz - cnt) + (sz - cnt) * (sz - cnt - 1) / 2 *  a * i;
    }
    for(int i = 0; i < n; i++)
        sort(G[i].begin(), G[i].end());
    for(int i = 1; i <= m; i++) {
      auto u = G[x[i]].begin(), v = G[y[i]].begin();
      while(u != G[x[i]].end() && v != G[y[i]].end()) {
        if(*u == *v) {
          int t[3] = {x[i], y[i], *u};
          sort(t, t + 3);
          ans -=  (t[0] * a + t[1] * b + t[2] * c);
          u++;v++;
        }else if(*u < *v)
           u++;
         else if(*u > *v)
           v++;
      }
    }
    cout << ans << endl;
    return 0;
}