#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    cin >> n >> s;
    for (int i=1;i<=n-1;i++)
    {
        if (s[i-1]!=s[i])
        {
            cout << "YES" << endl;
            cout << s[i-1] << s[i];
            return 0;
        }
    }
    cout << "NO";
}