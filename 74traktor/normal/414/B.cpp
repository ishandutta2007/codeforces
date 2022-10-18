#include <bits/stdc++.h>

using namespace std;
#define int long long
vector < int > a[2001];
int mod = 1e9 + 7;
int matr[2001][2001];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= i; ++j){
            if (i % j == 0)
                a[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; ++i)
        matr[1][i] = 1;
    for (int i = 2; i <= k; ++i){
        for (int j = 1; j <= n; ++j){
            for (auto key : a[j]){
                matr[i][j] = (matr[i][j] + matr[i - 1][key]) % mod;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += matr[k][i];
    cout << ans % mod << endl;
    return 0;
}