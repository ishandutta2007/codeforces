#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
char a[N];

int main()
{
    cin >> a;
    n = strlen(a);

    int s = -1, k = -1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= '1' && a[i] <= '9' && s == -1)
            s = i;
        if (a[i] == '.')
            k = i;
    }
    if (k == -1)
    {
        a[n] = '.';
        k = n;
        ++n;
    }

    vector<char> v;
    for (int i = s + 1; i < n; ++i)
    {
        if (a[i] >= '0' && a[i] <= '9')
            v.push_back(a[i]);
    }
    while (!v.empty() && v.back() == '0')
        v.pop_back();

    if (!v.empty())
        cout << a[s] << '.';
    else
        cout << a[s];
    for (int i = 0; i < v.size(); ++i)
        cout << v[i];
    if (k == s + 1)
        return 0;
    if (k > s + 1)
        cout << 'E' << k - s - 1;
    else
        cout << 'E' << k - s;

    return 0;
}