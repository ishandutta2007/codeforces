#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 3;
const int MAXM = 6;

string a[MAXN];
int d[MAXN];
string s[MAXM];


int modify(string &a)
{
    for (int i = 0; i < (int)a.size(); i++)
        if ('a' <= a[i] && a[i] <= 'z')
            a[i] -= (int)('a' - 'A');

    int n = 0;
    for (int i = 0; i < (int)a.size(); i++)
        if ('A' <= a[i] && a[i] <= 'Z')
            a[n++] = a[i];
    a.resize(n);
    return 0;
}

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/

    for (int i = 0; i < MAXN; i++)
    {
        getline(cin, a[i]);
        modify(a[i]);
    }

    for (int i = 0; i < MAXN; i++)
        d[i] = i;

    int m = 0;
    do
    {
        s[m] = "";
        for (int i = 0; i < MAXN; i++)
            s[m] += a[d[i]];
        m++;
    } while (next_permutation(d, d + MAXN));

    int n;
    scanf("%d\n", &n);
    while (n--)
    {
        string c;
        getline(cin, c);
        modify(c);
        bool f = false;
        for (int i = 0; i < m && !f; i++)
            f = s[i] == c;

        cout << (f? "ACC" : "WA") << endl;
    }
    
    return 0;
}