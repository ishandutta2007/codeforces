#include <bits/stdc++.h>

using namespace std;

char a[505][505];
int up[505][505];
int lef[505][505];
int righ[505][505];
int down[505][505];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
    int cnt = 0;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (a[i][j] == '*') cnt++;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == '*'){
                up[i][j]++;
                lef[i][j]++;
                up[i][j] += up[i - 1][j];
                lef[i][j] += lef[i][j - 1];
            }
        }
    }
    for (int i = n; i >= 1; --i){
        for (int j = m; j >= 1; --j){
            if (a[i][j] == '*'){
                down[i][j]++;
                righ[i][j]++;
                down[i][j] += down[i + 1][j];
                righ[i][j] += righ[i][j + 1];
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (min({lef[i][j], up[i][j], righ[i][j], down[i][j]}) <= 1) continue;
            if (lef[i][j] + up[i][j] + righ[i][j] + down[i][j] - 3 == cnt){
                cout << "YES" << '\n';
                return 0;
            }
        }
    }
    cout << "NO" << '\n';
    return 0;
}