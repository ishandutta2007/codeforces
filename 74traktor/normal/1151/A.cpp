#include <bits/stdc++.h>

using namespace std;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 10000;
    int h1 = 'T' - 'A', h2 = 'G' - 'A';
    for (int i = 0; i < n - 3; ++i){
        int c = s[i] - 'A', c1 = s[i + 1] - 'A', c2 = s[i + 2] - 'A', c3 = s[i + 3] - 'A';
        int g = 0;
        g += min(c, 26 - c);
        if (c1 <= 2){
            g += (2 - c1);
        }
        else{
            g += min(abs(2 - c1), 28 - c1);
        }
        if (c2 <= h1){
            g += min(abs(c2 - h1), 26 - h1 + c2);
        }
        else{
            g += min(abs(c2 - h1), h1 + 26 - c2);
        }
        if (c3 <= h2){
            g += min(abs(c3 - h2), 26 - h2 + c3);
        }
        else{
            g += min(abs(c3 - h2), h2 + 26 - c3);
        }
        ans = min(ans, g);
    }
    cout << ans << '\n';
    return 0;
}