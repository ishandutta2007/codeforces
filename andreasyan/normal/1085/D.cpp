#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
long double s;
vector<int> a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(18);
    cin >> n >> s;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].size() == 1)
            ++q;
    }
    cout << (s / q) * 2 << endl;
    return 0;
}