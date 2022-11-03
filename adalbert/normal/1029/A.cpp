#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;

    string st1;
    cin >> st1;

    int mx = 0;

    for (int i = 1; i < st1.size(); i++)
    {
        bool ch = 1;
        for (int j = 0; j<i; j++)
            if (st1[st1.size() - i + j] != st1[j])
            ch = 0;
        if (ch)
            mx = i;
    }

    string res = "";

    res = st1;
    while (mx--)
    {
        st1.erase(st1.begin());
    }

    m--;
    while (m--)
        res += st1;

    cout << res;
}