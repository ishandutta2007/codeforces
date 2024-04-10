#include <bits/stdc++.h>

using namespace std;

int used[1005][1005];
int ans[1000005];
int numb[1005][1005];
int tmp;
char a[1005][1005];
vector < pair < int, int > > to = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int i, int j){
    used[i][j] = 1;
    numb[i][j] = tmp;
    for (auto key : to){
        int x = i + key.first, y = j + key.second;
        if (a[x][y] == '.'){
            if (used[x][y] == 0) dfs(x, y);
        }
        else ans[tmp]++;
    }
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, x, y;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == '.' && used[i][j] == 0){
                tmp++;
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i <= k; ++i){
        cin >> x >> y;
        cout << ans[numb[x][y]] << '\n';
    }
    return 0;
}