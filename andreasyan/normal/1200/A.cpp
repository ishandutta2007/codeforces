#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

bool c[10];

int n;
char a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> a;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'L')
        {
            for (int j = 0; j < 10; ++j)
            {
                if (!c[j])
                {
                    c[j] = true;
                    break;
                }
            }
        }
        else if (a[i] == 'R')
        {
            for (int j = 9; j >= 0; --j)
            {
                if (!c[j])
                {
                    c[j] = true;
                    break;
                }
            }
        }
        else
        {
            c[a[i] - '0'] = false;
        }
    }
    for (int i = 0; i < 10; ++i)
        cout << c[i];
    cout << endl;
    return 0;
}