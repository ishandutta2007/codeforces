#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
string s;
int a[100010];
string copy(string s, int st, int en)
{
    string s1 = "";
    for (int i = st; i <= en; i++)
        s1 += s[i];
    return s1;
}

int f(string s)
{
    int n;

    n = s.length();
    if (n >= 4 && "lios" == copy(s, n - 4, n - 1))
        return 1;
    if (n >= 5 && "liala" == copy(s, n - 5, n - 1))
        return 2;
    if (n >= 3 && "etr" == copy(s, n - 3, n - 1))
        return 3;
    if (n >= 4 && "etra" == copy(s, n - 4, n - 1))
        return 4;
    if (n >= 6 && "initis" == copy(s, n - 6, n - 1))
        return 5;
    if (n >= 6 && "inites" == copy(s, n - 6, n - 1))
        return 6;

    return -1;
}

/*
     -lios,     -liala.
     -etr,     -etra.
     -initis,     -inites.*/

int main()
{
    int i = 0, d, n;
    cin >> s;
    while (s != "")
    {
        d = f(s);
        a[i] = d;
        i++;
        s = "";
        cin >> s;
    }
    n = i;
    if (n == 1 && a[0] != -1)
    {
        cout << "YES";
        return 0;
    }
    for (i = 0; i < n; i++)
        if (a[i] == -1)
         {
            cout << "NO";
            return 0;
        }
    for (i = 1; i < n; i++)
        if (a[i - 1] % 2 != a[i] % 2)
        {
            cout << "NO";
            return 0;
        }
    i = 0;
    while (a[i] == 1 || a[i] == 2)
        i++;
    if (not (a[i] == 3 || a[i] == 4))
    {
        cout << "NO";
        return 0;
    }
    i++;
    while (a[i] == 5 || a[i] == 6)
        i++;
    if (i != n)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";

    return 0;
}