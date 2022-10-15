#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100500;



const string c[2][3] = {{"lios", "etr", "initis"}, {"liala", "etra", "inites"}};

string a[MAXN];
int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    while (cin >> a[n]) n++;

    if (n == 1)
    {
        bool f = false;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                f |= c[i][j].size() <= a[0].size() && a[0].substr((int)a[0].size() - (int)c[i][j].size()) == c[i][j];
        puts(f? "YES" : "NO");
        return 0;
    }


    for (int i = 0; i < 2; i++)
    {
        int j = 0;
        while (j < n && c[i][0].size() <= a[j].size() && a[j].substr((int)a[j].size() - (int)c[i][0].size()) == c[i][0]) j++;

        if (j < n && c[i][1].size() <= a[j].size() && a[j].substr((int)a[j].size() - (int)c[i][1].size()) == c[i][1])
            j++;
        else
            continue;

        while (j < n && c[i][2].size() <= a[j].size() && a[j].substr((int)a[j].size() - (int)c[i][2].size()) == c[i][2]) j++;
        if (j < n) continue;
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}