#include <bits/stdc++.h>
using namespace std;
const int N = 3000005;

int n;
char a[N];
int sh[N], s[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> a;
    for (int i = n - 1; i >= 0; --i)
    {
        sh[i] = sh[i + 1];
        s[i] = s[i + 1];
        if (a[i] == '(')
            s[i]++;
        else if (a[i] == ')')
            s[i]--;
        else
            sh[i]++;
    }
    int p = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '(')
            ++p;
        else if (a[i] == ')')
            --p;
        else
        {
            if (p + 1 + s[i + 1] - sh[i + 1] <= 0)
            {
                a[i] = '(';
                ++p;
            }
            else
            {
                a[i] = ')';
                --p;
            }
        }
        if (p <= 0 && i != n - 1)
        {
            cout << ":(" << endl;
            return 0;
        }
    }
    if (p != 0)
    {
        cout << ":(" << endl;
        return 0;
    }
    cout << a << endl;
    return 0;
}