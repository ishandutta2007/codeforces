#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500000;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int a[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pair<int, int> b[MAXN];
    for (int i = 0; i < n; i++)
        b[i] = make_pair(a[i] - n + i + 1, a[i]);
    sort(b, b + n);
    int c[MAXN];
    for (int i = 0; i < n; i++)
        c[i] = b[i].first + n - i - 1;
    for (int i = 0; i < n - 1; i++)
        if (c[i] > c[i + 1])
        {
            cout << ":(";
            return 0;
        }
    for (int i = 0; i < n; i++)
        cout << c[i] << ' ';

    return 0;
}