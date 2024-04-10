#include <bits/stdc++.h>

using namespace std;

pair < int, int > a[200005];
int b[200005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x, y;
    cin >> n >> k;
    map < int, vector < int > > g;
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
        a[i] = {b[i], i};
        vector < int > prom;
        g[i] = prom;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; ++i){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    map < int, int > where;
    for (int i = 1; i <= n; ++i){
        where[a[i].second] = i;
    }
    int l, r, m, ans;
    for (int i = 1; i <= n; ++i){
        l = 0, r = n + 1;
        while (r - l > 1){
            m = (r + l) / 2;
            if (a[m].first < b[i])
                l = m;
            else
                r = m;
        }
        ans = l;
        for (auto key : g[i]){
            if (where[key] <= l)
                --ans;
        }
        cout << ans << " ";
    }
    return 0;
}