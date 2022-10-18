#include <bits/stdc++.h>

using namespace std;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int m, l, r, k;
    cin >> m;
    for (int i = 1; i <= m; ++i){
        cin >> l >> r >> k;
        l--;
        r--;
        k = k % (r - l + 1);
        string t = "";
        for (int j = l; j <= r; ++j) t += s[j];
        for (int j = l; j <= r; ++j) s[(j - l + k) % (r - l + 1) + l] = t[j - l];
        //cout << s << '\n';
    }
    cout << s << '\n';
    return 0;
}