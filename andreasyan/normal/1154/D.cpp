#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, b, a;
int aa;
int z[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> b >> a;
    for (int i = 1; i <= n; ++i)
    {
        cin >> z[i];
    }
    aa = a;
    for (int i = 1; i <= n; ++i)
    {
        if (z[i] == 0)
        {
            if (a != 0)
                --a;
            else if (b != 0)
                --b;
            else
            {
                cout << i - 1 << endl;
                return 0;
            }
        }
        else
        {
            if (a == aa)
                --a;
            else if (b != 0)
            {
                --b;
                if (a != aa)
                    ++a;
            }
            else if (a != 0)
                --a;
            else
            {
                cout << i - 1 << endl;
                return 0;
            }
        }
    }
    cout << n << endl;
    return 0;
}