#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;
const long long p = 1e9 + 7;

string s, s1, s2;
bool a1[10000];
bool a2[10000];
int n, n1, n2;
long long hash[3000];
long long step[3000];
long long a[5000000];

bool check1(int uk)
{
    for (int i = 0; i < n1; i++)
    {
        if (s1[i] != s[uk + i])
            return false;
    }
    return true;
}

bool check2(int uk)
{
    for (int i = 0; i < n2; i++)
    {
        if (s2[i] != s[uk + i])
            return false;
    }
    return true;
}

int main()
{
   int i, l, r, count = 0, len;
    cin >> s;
    cin >> s1;
    cin >> s2;
    n = s.length();
    n1 = s1.length();
    n2 = s2.length();

    step[0] = 1;
    for (i = 1; i <= n; i++)
        step[i] = step[i - 1] * p;
    hash[0] = 0;
    for (i = 1; i <= n; i++)
    {
        hash[i] = hash[i - 1] * p + s[i - 1];
    }

    for (i = 0; i <= n - n1; i++)
    {
        if (check1(i))
            a1[i] = true;
    }
    for (i = 0; i <= n - n2; i++)
    {
        if (check2(i))
            a2[i] = true;
    }
 /*   for (l = 0; l < n; l++)
    {
        for (r = l; r < n; r++)
        {
            if (r - l + 1 > max (n1, n2) && a1[l] && a2[r - n1 + 1])
            {
                len = r - l + 1;
                a[count] = (hash[r] - hash[l - 1] * step[len + 1]) * step[n - len - 1];
                count++;
            }
        }
    }*/
    for (l = 1; l <= n; l++)
    {
        for (len = 0; len <= n - l; len++)
        {
            r = l + len;
            if (r - l + 1 >= max (n1, n2) && a1[l - 1] && a2[r - n2])
            {
                a[count] = (hash[r] - hash[l - 1] * step[len + 1]) * step[n - len - 1];
                count++;
            }
        }
    }
    sort(a, a + count);
    int count1 = 0;
    if (count != 0)
        count1 = 1;
    for (i = 1; i < count; i++)
    {
        if (a[i - 1] != a[i])
            count1++;
    }
    cout << count1;

    return 0;
}