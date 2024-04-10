#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[N];

int main()
{
    cin >> n >> a;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            for (int j = 0; j < i; ++j)
                cout << a[j];
            for (int j = i + 1; j < n; ++j)
                cout << a[j];
            cout << endl;
            return 0;
        }
    }
    for (int i = 0; i < n - 1; ++i)
        cout << a[i];
    cout << endl;
    return 0;
}