#include <bits/stdc++.h>

using namespace std;

int N, M;
int tbl[1005][1005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        for(int j = 1; j<=n; j++){
            tbl[i][j] |= 1;
        }
        tbl[i][n+1] |= 2;
    }
    for(int j = 1; j<=M; j++){
        int n;
        cin >> n;
        for(int i = 1; i<=n; i++){
            tbl[i][j] |= 1;
        }
        tbl[n+1][j] |= 2;
    }
    long long ans = 1;
    for(int i = 1; i<=N; i++){
        for(int j =1; j<=M; j++){
            ans *= __builtin_popcount(3-tbl[i][j]);
            ans %= (long long) 1e9+7;
        }
    }
    cout << ans << endl;
}