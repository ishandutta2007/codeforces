#include <bits/stdc++.h>

using namespace std;

#define int long long
int mod = 998244353;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, p = 0;
    for (int i = n - 1; i >= 0; --i){
        if (s[i] == s[n - 1]) ans++;
        else break;
    }
    for (int i = 0; i <= n - 1; ++i){
        if (s[i] == s[n - 1]) ++p;
        else break;
    }
    int h1 = 0, h2 = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == s[0]) h1++;
        else break;
    }
    for (int i = n - 1; i >= 0; --i){
        if (s[i] == s[0]) h2++;
        else break;
    }
    //cout << ans << endl;
    cout << (ans + 1 + h1 * h2 + h1) % mod << endl;
    return 0;
}