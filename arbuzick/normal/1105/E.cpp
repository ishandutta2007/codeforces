#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
int g[40][40];
vector<int> g2(40);
vector<int> ans1(1 << 21), ans2(1 << 21);
int n, m;
bool check(int mask, int t){
    for(int i = m/2*t; i < m/2+(m/2+m%2)*t; ++i){
        if((mask&(1 << (i - m/2*t))) == 0)
            continue;
        for(int j = i+1; j < m/2+(m/2+m%2)*t; ++j)
            if(mask&(1 << (j - m/2*t)) && !g[i][j])
                return 0;
    }
    return 1;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    map<string, int> a;
    vector<vector<int>> b(n);
    int j = -1;
    int k = 1;
    for(int i = 0; i < n; ++i){
        int t;
        cin >> t;
        if(t == 1)
            j++;
        else{
            string s;
            cin >> s;
            if(a[s] == 0)
                a[s] = k, k++;
            b[j].pb(a[s]-1);
        }
    }
    for(int i = 0; i < n; ++i)
        for(int j1 = 0; j1 < b[i].size(); ++j1)
            for(int j2 = 0; j2 < b[i].size(); ++j2)
                g[b[i][j1]][b[i][j2]] = 1;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            g[i][j] = g[i][j]^1, g2[i] = g2[i]|(g[i][j] << j);
    for(int i = 0; i < m; ++i)
        g[i][i] = 1, g2[i] = g2[i]|(1 << i);
    for(int i = 0; i < (1 << m/2); ++i){
        if(check(i, 0)){
            int k = 0;
            for(int j = 0; j < m/2; ++j){
                if(i&(1 << j))
                    k++;
            }
            ans1[i] = k;
        }else{
            for(int j = 0; j < m/2; ++j)
                if(i&(1 << j))
                    ans1[i] = max(ans1[i], ans1[i^(1 << j)]);
        }
    }
    for(int i = 0; i < (1 << (m/2+m%2)); ++i){
        if(check(i, 1)){
            int k = 0;
            for(int j = 0; j < m/2+m%2; ++j)
                if(i&(1 << j))
                    k++;
            ans2[i] = k;
        }else{
            for(int j = 0; j < m/2+m%2; ++j)
                if(i&(1 << j))
                    ans2[i] = max(ans2[i], ans2[i^(1 << j)]);
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << m/2); ++i){
        int mask = (1 << (m/2+m%2))-1;
        for(int j1 = 0; j1 < m/2; ++j1){
            if(i&(1 << j1))
                mask = mask&(g2[j1] >> m/2);
        }
        ans = max(ans, ans1[i]+ans2[mask]);
    }
    cout << ans;
    return 0;
}