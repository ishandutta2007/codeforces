#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
/*
#include<climits>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
//*/

using namespace std;

string s, a, b;

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    cin >> s >> a >> b;

    int x, y;
    x = s.find(b);
    while ((y = s.find(b, x + 1)) != string::npos) x = y;

    bool fab = s.find(a) != string::npos && s.find(b) != string::npos && s.find(a) + a.size() <= x;
    reverse(s.begin(), s.end());

    x = s.find(b);
    while ((y = s.find(b, x + 1)) != string::npos) x = y;

    bool fba = s.find(a) != string::npos && s.find(b) != string::npos && s.find(a) + a.size() <= x;
    if (fab && fba) puts("both"); else
    if (fab) puts("forward"); else
    if (fba) puts("backward"); else
             puts("fantasy");

    return 0;
}