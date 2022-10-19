#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int sn, tn, pn;
char s[N], t[N], p[N];

int q[26], q2[26];
bool solv()
{
    cin >> s >> t >> p;
    sn = strlen(s);
    tn = strlen(t);
    pn = strlen(p);
    memset(q, 0, sizeof q);
    for (int i = 0; i < pn; ++i)
    {
        q[p[i] - 'a']++;
    }
    int i = 0;
    for (int j = 0; j < sn; ++j)
    {
        while (i + 1 < tn && t[i] != s[j])
            ++i;
        if (i < tn && t[i] == s[j])
        {
            t[i] = '0';
            ++i;
        }
        else
            return false;
    }
    memset(q2, 0, sizeof q2);
    for (int i = 0; i < tn; ++i)
    {
        if (t[i] != '0')
        {
            q2[t[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (q2[i] > q[i])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
    {
        if (solv())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}