#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double

const int MAXN = 2009;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int n;
int c[MAXN];

signed main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int e = 0; e < n; e++)
            a[i][e] = (s[e] == '1');
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int e = 0; e < n; e++)
        {
            int x = (s[e] == '1');
            a[i][e] ^= x;
        }
    }
    vector<int> v1;
    vector<int> v2;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        int x = (s[i] == '1');
        if (x == 1)
            v1.pb(i);
        else
            v2.pb(i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < n; e++)
        {
            if (i < (int)v1.size() && e < (int)v1.size())
                b[i][e] = a[v1[i]][v1[e]];
            else if (i < (int)v1.size())
                b[i][e] = a[v1[i]][v2[e - (int)v1.size()]];
            else if (e < (int)v1.size())
                b[i][e] = a[v2[i - (int)v1.size()]][v1[e]];
            else
                b[i][e] = a[v2[i - (int)v1.size()]][v2[e - (int)v1.size()]];
        }
    }
//    for (int i = 0; i < n; i++)
//        for (int e = 0; e < n; e++)
//        cout << b[i][e];
    vector<pii> ans;
    for (int i = (int)v1.size(); i < n; i++)
    {
        for (int e = (int)v1.size(); e < n; e++)
        {
            if (b[i][e])
            {
                cout << -1;
                return 0;
            }
        }
        if (b[i][0])
            ans.pb(0, v2[i - (int)v1.size()]);
        for (int e = 0; e < (int)v1.size(); e++)
        {
            if (b[i][e] != b[i][0])
            {
                cout << -1;
                return 0;
            }
        }
    }
    for (int e = (int)v1.size(); e < n; e++)
    {
        if (b[0][e])
            ans.pb(1, v2[e - (int)v1.size()]);
        for (int i = 0; i < (int)v1.size(); i++)
        {
            if (b[i][e] != b[0][e])
            {
                cout << -1;
                return 0;
            }
        }
    }
    for (int i = 0; i < (int)v1.size(); i++)
    {
        if (b[i][0])
            ans.pb(0, v1[i]);
        for (int e = 0; e < (int)v1.size(); e++)
        {
            if (b[i][e] != (b[i][0] ^ b[0][e] ^ b[0][0]))
            {
                cout << -1;
                return 0;
            }
        }
    }
    for (int e = 0; e < (int)v1.size(); e++)
    {
        if (b[0][e] ^ b[0][0])
            ans.pb(1, v1[e]);
    }
    cout << ans.size() << "\n";
    for (pii e : ans)
    {
        if (e.ff == 0)
            cout << "row ";
        else
            cout << "col ";
        cout << e.ss << "\n";
    }
}