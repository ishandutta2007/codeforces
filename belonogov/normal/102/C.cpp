#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
struct g
{
    int k, r;
    char ch;
};
bool f1 (g a, g b)
{
    return a.k < b.k;
}

bool f2 (g a, g b)
{
    return a.ch < b.ch;
}
g a[100];

int main()
{
     string s;
    int n, i, k, count = 0;
    cin >> s;
    cin >> k;
    n = s.length();
    for (i = 0; i < 26; i++)
        a[i].ch = 'a' + i;
    for (i = 0; i < n; i++)
    {
        a[s[i] - 'a'].k++;
    }
    sort(a, a + 26, f1);
    for (i = 0; i < 26; i++)
    {
        if (k > 0)
        {
            if (k >= a[i].k)
            {
                a[i].r = a[i].k;
                k -= a[i].k;
                a[i].k = 0;
            }
            else
            {
                a[i].r = k;
                a[i].k -= k;
                k = 0;
            }
        }
        if (a[i].k == 0)
            count++;
    }
    sort(a, a + 26, f2);
    cout << 26 - count << "\n";
    for (i = 0; i < n; i++)
    {
        if (a[s[i] - 'a'].r > 0)
            a[s[i] - 'a'].r--;
        else
            cout << s[i];
    }
    return 0;
}