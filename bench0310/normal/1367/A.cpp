#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        cout << s[0];
        for(int i=1;i<(int)s.size();i+=2) cout << s[i];
        cout << "\n";
    }
    return 0;
}