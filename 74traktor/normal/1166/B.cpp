#include <bits/stdc++.h>

using namespace std;

#define int long long

vector < char > Q = {'a', 'e', 'o', 'u', 'i'};

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, n, m;
    cin >> k;
    for (int i = 1; i <= k; ++i){
        if (k % i == 0){
            n = i, m = k / i;
            if (n >= 5 && m >= 5){
                string ans = "";
                for (int i1 = 1; i1 <= n; ++i1){
                    for (int j = 1; j <= m; ++j){
                        int sd = (i1 - 1) % 5, numb = (j - 1) % 5;
                        ans += Q[(numb + sd) % 5];
                    }
                }
                cout << ans << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}