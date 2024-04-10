#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    map<string, int> m;
    for (int i = 0; i < n - 1; i++)
    {
        string r = "";
        r += s[i];
        r += s[i + 1];
        m[r] += 1;
    }
    int ma = 0;
    string ans;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        if ((*i).second > ma)
        {
            ma = (*i).second;
            ans = (*i).first;
        }
    }
    cout << ans;
}