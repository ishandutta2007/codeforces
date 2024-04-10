#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void fail()
{
    cout << "NO" << endl;
    exit(0);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<char> lol;
    for(auto c: s)
    {
        if(lol.empty() && c != 'a' || !lol.empty() && lol.back() < c && lol.back() + 1 != c)
            fail();
        if(lol.empty() || lol.back() + 1 == c)
            lol.push_back(c);
    }
    cout << "YES" << endl;
}