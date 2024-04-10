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
    ios::sync_with_stdio(0);
    string a = "Bulbasaur";
    map <char, int> cnt;
    string s;
    cin >> s;
    for (auto c : s)
    {
        cnt[c]++;
    }
    int res = 1e9;
    for (auto c : a)
    {
        if (c == 'a' || c == 'u')
        {
            res = min(res, cnt[c] / 2);
        }
        else
        {
            res = min(res, cnt[c]);
        }
    }
    cout << res << '\n';
}