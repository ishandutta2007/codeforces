#include <bits/stdc++.h>

using namespace std;

unordered_map < int, int > sum;
unordered_map < int, int > razn;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x >> y;
        sum[x + y]++;
        razn[x - y]++;
    }
    int ans = 0;
    for (auto key : sum) ans += key.second * (key.second - 1) / 2;
    for (auto key : razn) ans += key.second * (key.second - 1) / 2;
    cout << ans << endl;
    return 0;
}