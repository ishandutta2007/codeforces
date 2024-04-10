#include <bits/stdc++.h>
using namespace std;
const char b[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
const int N = 102;

int n;
char a[N];

bool stg(char t)
{
    for (int i = 0; i < 6; ++i)
    {
        if (b[i] == t)
            return true;
    }
    return false;
}

int main()
{
    cin >> n;
    cin >> a;
    for (int i = 0; i < n; ++i)
    {
        if (i && stg(a[i]) && stg(a[i - 1]))
            continue;
        cout << a[i];
    }
    cout << endl;
    return 0;
}