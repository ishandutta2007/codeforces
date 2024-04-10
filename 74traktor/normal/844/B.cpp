#include <bits/stdc++.h>

using namespace std;

#define int long long

int matr[52][52];
int row[52][2];
int col[52][2];


int Ch(int n, int k){
    int tmp = 1;
    vector < pair < int, int > > Q;
    for (int i = 1; i <= k; ++i) Q.push_back({i, 0});
    for (int i = n - k + 1; i <= n; ++i){
        tmp *= i;
        for (int j = 0; j < k; ++j){
            if (Q[j].second == 0 && tmp % Q[j].first == 0) tmp /= Q[j].first, Q[j] = {Q[j].first, 1};
        }
    }
    return tmp;
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j) cin >> matr[i][j];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j) row[i][matr[i][j]]++, col[j][matr[i][j]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int k = 1; k <= row[i][0]; ++k) ans += Ch(row[i][0], k);
        for (int k = 1; k <= row[i][1]; ++k) ans += Ch(row[i][1], k);
    }
    for (int i = 1; i <= m; ++i){
        for (int k = 1; k <= col[i][0]; ++k) ans += Ch(col[i][0], k);
        for (int k = 1; k <= col[i][1]; ++k) ans += Ch(col[i][1], k);
    }
    cout << ans - n * m << endl;
    return 0;
}