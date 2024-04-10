#include <bits/stdc++.h>

using namespace std;

#define int long long

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector < vector < int > > Q;
    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a >> b;
        Q.push_back({a - b, a, b});
    }
    sort(Q.begin(), Q.end());
    int ans = 0, pos = n;
    for (auto key : Q){
        ans += key[1] * (pos - 1) + key[2] * (n - pos);
        pos--;
    }
    cout << ans << '\n';
    return 0;
}