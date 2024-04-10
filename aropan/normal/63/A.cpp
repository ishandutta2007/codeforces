#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;

#define X first.first
#define I first.second
#define S second

pair < pair <int, int>, string > a[MAXN];
int n;

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> a[i].S >> s;
        if (s == "rat") a[i].X = 0; else
        if (s == "woman") a[i].X = 1; else
        if (s == "child") a[i].X = 1; else
        if (s == "man") a[i].X = 2; else
        if (s == "captain") a[i].X = 3;
        a[i].I = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i].S << endl;
    return 0;
}