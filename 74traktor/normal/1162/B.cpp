#include <bits/stdc++.h>

using namespace std;

int a[52][52];
int b[52][52];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j) cin >> b[i][j];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
        }
    }
    bool f = true;
    for (int i = 1; i <= n; ++i){
        for (int j = 2; j <= m; ++j){
            if (a[i][j - 1] >= a[i][j]) f = false;
            if (b[i][j - 1] >= b[i][j]) f = false;
        }
    }
    for (int j = 1; j <= m; ++j){
        for (int i = 2; i <= n; ++i){
            if (a[i - 1][j] >= a[i][j]) f = false;
            if (b[i - 1][j] >= b[i][j]) f = false;
        }
    }
    if (f) cout << "Possible" << '\n';
    else cout << "Impossible" << '\n';
    return 0;
}