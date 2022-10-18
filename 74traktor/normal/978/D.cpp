#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
long long a[100005];
long long ans = 1e9, sum_tec;

void dfs(int pr, int pt){
    int pocl = a[2] + pt;
    for (int i = 3; i <= n; ++i){
        if (abs(a[i] - (pocl + pr)) == 1){
            pocl = pocl + pr;
            sum_tec++;
        }
        else if (a[i] != pocl + pr){
            sum_tec = 1e12;
            return;
        }
        else pocl += pr;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n <= 2){
        cout << 0 << endl;
        return 0;
    }
    for (int i = -1; i <= 1; ++i){
        for (int j = -1; j <= 1; ++j){
            sum_tec = 0;
            dfs((a[2] + i) - (a[1] + j), i);
            ans = min(ans, sum_tec + abs(i) + abs(j));
        }
    }
    if (ans == (int)1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}