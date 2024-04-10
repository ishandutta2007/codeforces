#include <bits/stdc++.h>

using namespace std;

int a[100005];
int used[100005];
int righ[100005];
int lef[100005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i){
        cin >> a[i];
        used[a[i]] = 1;
        righ[a[i]] = i;
        if (lef[a[i]] == 0) lef[a[i]] = i;
    }
    int ans = 0;
    for (int j = 1; j <= n; ++j){
        if (used[j] == 0){
            if (j == 1 || j == n) ans += 2;
            else ans += 3;
        }
        else{
            if (used[j + 1] == 0 && j < n) ans++;
            else if (j < n && righ[j + 1] < lef[j]) ans++;
            if (used[j - 1] == 0 && j > 1) ans++;
            else if (j > 1 && righ[j - 1] < lef[j]) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}