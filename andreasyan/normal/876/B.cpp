#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m, k;
int a[N];

vector<int> v[N];

int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        v[a[i] % m].push_back(a[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        if (v[i].size() >= k)
        {
            cout << "Yes" << endl;
            for (int j = 0; j < k; ++j)
                cout << v[i][j] << ' ';
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}