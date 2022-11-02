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

const int MAXN = 200009;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 == 1)
    {
        cout << "No";
        return 0;
    }
    bool u = false;
    int bal = 0;
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        if (!u && s[i] == ')')
            u = true;
        else if (s[i] == '(')
            bal++;
        else
            bal--;
        if (bal < 0)
            check = false;
    }
    if (u)
        bal--;
    if (bal == 0 && check)
    {
        cout << "Yes";
        return 0;
    }
    u = false;
    bal = 0;
    check = true;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!u && s[i] == '(')
            u = true;
        else if (s[i] == ')')
            bal++;
        else
            bal--;
        if (bal < 0)
            check = false;
    }
    if (u)
        bal--;
    if (bal == 0 && check)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
}