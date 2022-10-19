#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];
char b[N];

bool ans[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> b;
    int l = -1000000000, r = 1000000000;
    for (int i = 4; i < n; ++i)
    {
        if (b[i] != b[i - 1])
        {
            if (b[i] == '1')
            {
                for (int j = i; j >= i - 4; --j)
                    l = max(l, a[j] + 1);
            }
            else
            {
                for (int j = i; j >= i - 4; --j)
                    r = min(r, a[j] - 1);
            }
        }
    }
    cout << l << ' ' << r << endl;
    return 0;
}