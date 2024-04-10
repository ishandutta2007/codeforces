#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, k;
char a[N];

char minu, maxu;

bool c[26];

int main()
{
    cin >> n >> k;
    cin >> a;
    minu = a[0];
    maxu = a[0];
    for (int i = 0; i < n; ++i)
    {
        minu = min(minu, a[i]);
        maxu = max(maxu, a[i]);
        c[a[i] - 'a'] = true;
    }
    if (k > n)
    {
        cout << a;
        for (int i = 0; i < k - n; ++i)
        {
            cout << minu;
        }
        cout << endl;
        return 0;
    }
    int u = -1;
    for (int i = k - 1; i >= 0; --i)
    {
        if (a[i] < maxu)
        {
            u = i;
            break;
        }
    }
    for (int i = 0; i < u; ++i)
        cout << a[i];
    for (int j = a[u] - 'a' + 1; j < 26; ++j)
    {
        if (c[j])
        {
            cout << (char)(j + 'a');
            break;
        }
    }
    for (int j = u + 1; j < k; ++j)
        cout << minu;
    cout << endl;
    return 0;
}