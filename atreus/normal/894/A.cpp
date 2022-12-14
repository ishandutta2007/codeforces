#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int ans = 0, q = 0, k = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'Q')
            q ++;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'Q')
            k ++;
        if (s[i] == 'A')
            ans += k * (q - k);
    }
    cout << ans << endl;
}