#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
char a[N];

int main()
{
    cin >> n;
    cin >> a;
    int z = 0, m = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'z')
            ++z;
        if (a[i] == 'n')
            ++m;
    }
    for (int i = 0; i < m; ++i)
        cout << "1 ";
    for (int i = 0; i < z; ++i)
        cout << "0 ";
    cout << endl;
    return 0;
}