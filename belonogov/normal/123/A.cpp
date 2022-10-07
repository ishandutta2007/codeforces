#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
int a[100];
char ans[2000];
string s, s1;
bool f(int x)
{
    int i;
    if (x == 1)
        return true;
    for (i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;

    return true;
}

int main()
{
   int n, i, res, k, j, uk;
    cin >> s;
    n = s.length();
    if (n <= 3)
    {
        cout << "YES\n";
        cout << s;
        return 0;
    }
    for (i = 0; i < n; i++)
        a[s[i] - 'a']++;
    res = n - 1;
    for (i = n / 2 + 1; i <= n; i++)
    {
        if (f(i))
            res--;
    }
    k = 0;
    for (i = 0; i < 30; i++)
    {
        if (a[i] > a[k])
            k = i;
    }
    if (a[k] < res)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (i = 0; i < 30; i++)
    {
        if (i != k)
        {
            for (j = 0; j < a[i]; j++)
                s1 += 'a' + i;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (! ((i == 0) || ((i + 1 > n / 2) && f(i + 1))))
        {
            ans[i] = (char)(k + 'a');
            a[k]--;
        }
    }
    uk = 0;
    for (i = 0; i < n; i++)
    {
        if ((i == 0) || ((i + 1 > n / 2) && f(i + 1)))
        {
            while (a[uk] == 0)
                uk++;
            ans[i] = (char)(uk + 'a');
            a[uk]--;
        }

    }
/*   for (i = 0; i < n; i++)
    {
        if ((i == 0) || ((i + 1 > n / 2) && f(i + 1)))
        {
            cout << s1[uk];
            uk++;
        }
        else
        {
            ch = (char)(k + 'a');
            cout << ch;

        }
    }
*/
    for (i = 0; i < n; i++)
        cout << ans[i];
    return 0;
}