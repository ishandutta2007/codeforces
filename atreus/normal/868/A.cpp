#include <bits/stdc++.h>

using namespace std;

string s[120];

int main(){
    string a, ans = "NO";
    cin >> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        if (s[i] == a)
            ans = "YES";
    }
    bool cur = false;
    for (int i = 0; i < n; i++){
        if (s[i][1] == a[0])
            cur = true;
    }
    for (int i = 0; cur == true && i < n; i++){
        if (s[i][0] == a[1])
            ans = "YES";
    }
    cout << ans << endl;
}