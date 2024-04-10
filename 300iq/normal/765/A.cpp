#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        string f = "";
        f += a;
        f += b;
        f += c;
        string t = "";
        cin >> c;
        cin >> c;
        cin >> a >> b >> c;
        t += a;
        t += b;
        t += c;
        if (f == s)
        {
            cnt++;
        }
        else
        {
            d++;
        }
    }
    if (cnt == d)
    {
        cout << "home\n";
    }
    else
    {
        cout << "contest\n";
    }
}