#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

string t;
string s[5];

int main()
{
    cin >> t;
    for (int i = 0; i < 5; ++i)
        cin >> s[i];
    for (int i = 0; i < 5; ++i)
    {
        if (s[i][0] == t[0] || s[i][1] == t[1])
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}