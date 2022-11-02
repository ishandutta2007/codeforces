#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    if (n == 1)
        cout << -1;
    else if (n == 2 && a[0].first == a[1].first)
        cout << -1;
    else
        cout << 1 << "\n" << a[0].second + 1;
}