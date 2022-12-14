#include <bits/stdc++.h>

using namespace std;

bool isupper(char c){
    if (c - 'A' > 26)
        return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int ans = 0;
    int lc = 0, up = 0;
    for (int i = 0; i < s.size(); i++)
        if (isupper(s[i]))
            up ++;
    ans = up;
    for (int i = 0; i < s.size(); i++){
        if (isupper(s[i]))
            up --;
        else
            lc ++;
        ans = min (ans, lc + up);
    }
    cout << ans << endl;
}