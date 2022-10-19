#include <bits/stdc++.h>
using namespace std;
const int N = 300005;

int n;
char a[N];

int main()
{
    cin >> n >> a;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            cout << "YES" << endl;
            cout << i << ' ' << i + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}