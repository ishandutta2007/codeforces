#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int sum;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    int p = 0;
    for (int i = 1; i <= n; ++i)
    {
        p += a[i];
        if (p * 2 >= sum)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}