#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[55][2];
int used[55][55];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1];
    vector < vector < int > > Q;
    for (int i = 1; i <= n; ++i){
        for (int j = 2; j <= n; ++j){
            if (used[i][j] == 1) continue;
            vector < int > pos;
            int A = a[i][1] - a[j][1], B = a[j][0] - a[i][0], C = a[i][0] * a[j][1] - a[i][1] * a[j][0];
            for (int z = 1; z <= n; ++z){
                if (a[z][0] * A + B * a[z][1] + C == 0) pos.push_back(z);
            }
            for (auto key : pos){
                for (auto key1 : pos){
                    used[key][key1] = 1;
                }
            }
            Q.push_back({A, B, C});
        }
    }
    int ans = 0;
    for (auto key : Q){
        for (auto key1 : Q){
            if (key[0] * key1[1] == key[1] * key1[0]) continue;
            ans++;
        }
    }
    cout << ans / 2 << '\n';
    return 0;
}