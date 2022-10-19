#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m;
char a[N], b[N];

bool c[26];
int main()
{
    c['a' - 'a'] = true, c['e' - 'a'] = true, c['i' - 'a'] = true, c['o' - 'a'] = true, c['u' - 'a'] = true;
    cin >> a >> b;
    n = strlen(a);
    m = strlen(b);
    if (n != m)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        if (c[a[i] - 'a'] != c[b[i] - 'a'])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}