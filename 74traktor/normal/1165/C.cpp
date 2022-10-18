#include <bits/stdc++.h>

using namespace std;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s, ans = "";
    cin >> s;
    if (n == 1){
        cout << 1 << '\n';
        return 0;
    }
    int i = 0, j = 1;
    while (i < n){
        while (j < n && s[i] == s[j]) ++j;
        if (j == n) break;
        ans += s[i];
        ans += s[j];
        i = j + 1;
        ++j;
    }
    cout << n - (int)ans.size() << '\n';
    cout << ans << '\n';
    return 0;
}