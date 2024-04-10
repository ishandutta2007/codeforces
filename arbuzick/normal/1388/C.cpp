#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
vector<vector<int>> g;
vector<int> s, s1, s2;
int dfs1(int v, int pr){
    int k = 0;
    for(auto u: g[v])
        if(u != pr)
            k += dfs1(u, v);
    s[v] += k;
    return s[v];
}
bool dfs2(int v, int pr){
    bool r = 1;
    int s11 = 0, s21 = 0;
    for(auto u: g[v]){
        if(u != pr){
            r = r&&dfs2(u, v);
            s11 += s1[u], s21 += s2[u];
        }
    }
    //cout << s11 << ' ' << s21 << ' ' << s1[v] << ' ' << s2[v] << '\n';
    if(s21 > s2[v])
        r = 0;
    return r;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        s.assign(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> s[i];
        vector<int> h(n);
        for(int i = 0; i < n; ++i)
            cin >> h[i];
        g.assign(n, vector<int>(0));
        for(int i = 0; i < n-1; ++i){
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].pb(y);
            g[y].pb(x);
        }
        dfs1(0, 0);
        bool ans = 1;
        s1.assign(n, 0);
        s2.assign(n, 0);
        for(int i = 0; i < n; ++i){
            if(abs(h[i]) > s[i] || abs(h[i])%2 != s[i]%2)
                ans = 0;
            s1[i] = (s[i]-h[i])/2;
            s2[i] = s[i]-s1[i];
            //cout << s[i] << ' ' << h[i] << ' ' << s1[i] << ' ' << s2[i] << '\n';
        }
        ans = ans&&dfs2(0, 0);
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}