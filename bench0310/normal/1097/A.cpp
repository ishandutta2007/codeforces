#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    bool ok=0;
    for(int i=0;i<5;i++)
    {
        string t;
        cin >> t;
        ok|=(t[0]==s[0]||t[1]==s[1]);
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}