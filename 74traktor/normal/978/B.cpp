#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, num = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == 'x')
            num++;
        else
            num = 0;
        if (num >= 3)
            ans++;
    }
    cout << ans << endl;
    return 0;
}