#include <bits/stdc++.h>
using namespace std;
const int N = 502;

int n;
char a[N];

bool c[26];
void solv()
{
    memset(c, false, sizeof c);
    cin >> a;
    n = strlen(a);
    int q = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i - 1])
        {
            ++q;
        }
        else
        {
            if (q % 2 == 1)
                c[a[i - 1] - 'a'] = true;
            q = 1;
        }
    }
    if (q % 2 == 1)
    {
        c[a[n - 1] - 'a'] = true;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (c[i])
            cout << (char)(i + 'a');
    }
    cout << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}