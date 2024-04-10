#include <bits/stdc++.h>
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
int dp[1000000][8];
int dp2[1000000][8][2];
vector<string> a;
int t[8][4];
int change(int i, int j, int t1){
    int r = 0;
    int k = a[i+1][j+1]-'0';
    r += abs(k-t[t1][3]);
    if(i == 0){
        k = a[i][j+1]-'0';
        r += abs(k-t[t1][1]);
    }
    if(j == 0){
        k = a[i+1][j]-'0';
        r += abs(k-t[t1][2]);
    }
    if(i == 0 && j == 0){
        k = a[i][j]-'0';
        r += abs(k-t[t1][0]);
    }
    return r;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> l(8);
    l[0] = {1, 7}, l[1] = {0, 2}, l[2] = {3, 5}, l[3] = {0, 2};
    l[4] = {3, 5}, l[5] = {4, 6}, l[6] = {1, 7}, l[7] = {4, 6};
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(i == j)
                t[i][j] = 1, t[i+4][j] = 0;
            else
                t[i][j] = 0, t[i+4][j] = 1;
        }
    }
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n >= 4 && m >= 4){
        cout << -1;
        return 0;
    }
    if(min(n, m) == 1){
        cout << 0;
        return 0;
    }
    if(n >= 4){
        vector<string> a1(m);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j)
                a1[i] += a[j][i];
        }
        a = a1;
        swap(n, m);
    }
    if(n == 2){
        for(int i = 0; i < 8; ++i)
            dp[0][i] = change(0, 0, i);
        for(int i = 1; i+1 < m; ++i){
            for(int j = 0; j < 8; ++j){
                dp[i][j] = n*m;
                int k = change(0, i, j);
                for(auto j2: l[j])
                    dp[i][j] = min(dp[i][j], dp[i-1][j2]+k);
            }
        }
        int ans = n*m;
        for(int i = 0; i < 8; ++i)
            ans = min(ans, dp[m-2][i]);
        cout << ans;
        return 0;
    }
    vector<vector<int>> u(8);
    u[0] = {2, 7}, u[1] = {3, 6}, u[2] = {0, 1}, u[3] = {0, 1};
    u[4] = {3, 6}, u[5] = {2, 7}, u[6] = {4, 5}, u[7] = {4, 5};
    for(int i = 0; i < 8; ++i)
        for(int j: {0, 1})
            dp2[0][i][j] = change(1, 0, i)+change(0, 0, u[i][j]);
    for(int i = 1; i+1 < m; ++i){
        for(int j1 = 0; j1 < 8; ++j1)
            for(int j2: {0, 1}){
                dp2[i][j1][j2] = n*m;
                int k = change(1, i, j1)+change(0, i, u[j1][j2]);
                for(int j3: l[j1]){
                    for(int j4: {0, 1})
                        if(l[u[j1][j2]][0] == u[j3][j4] || l[u[j1][j2]][1] == u[j3][j4])
                            dp2[i][j1][j2] = min(dp2[i][j1][j2], dp2[i-1][j3][j4]+k);
                }
            }
    }
    int ans = n*m;
    for(int j1 = 0; j1 < 8; ++j1)
        for(int j2: {0, 1})
            ans = min(ans, dp2[m-2][j1][j2]);
    cout << ans;
    return 0;
}