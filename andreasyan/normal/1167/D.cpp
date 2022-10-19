#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[N];

char ans[N];
int main()
{
    cin >> n;
    cin >> a;
    int q0 = 0, q1 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '(')
        {
            if (q0 < q1)
            {
                ans[i] = '0';
                q0++;
            }
            else
            {
                ans[i] = '1';
                q1++;
            }
        }
        else
        {
            if (q0 > q1)
            {
                ans[i] = '0';
                q0--;
            }
            else
            {
                ans[i] = '1';
                q1--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}