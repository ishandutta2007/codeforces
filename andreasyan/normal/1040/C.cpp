#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
long long t;
long long a[N];
int x[N];

bool c[N];
int p[N];

long long b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    for (int i = 1; i <= n; ++i)
    {
        if (x[i] < i)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        c[x[i]] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] + c[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (p[x[i] - 1] - p[i - 1] > 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    b[n] = 3000000000000000000;
    for (int i = n - 1; i >= 1; --i)
    {
        if (c[i])
        {
            b[i] = a[i + 1] + t - 1;
            if (b[i] >= b[i + 1])
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            b[i] = b[i + 1] - 1;
            if (b[i] < a[i + 1] + t)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i)
        cout << b[i] << ' ';
    cout << endl;
    return 0;
}