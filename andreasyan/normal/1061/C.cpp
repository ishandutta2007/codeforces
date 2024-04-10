#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 1000000007;

int n;
int a[N];

int q[N * 10];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    q[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        vector<int> v;
        for (int j = 1; j * j <= a[i]; ++j)
        {
            if (a[i] % j == 0)
            {
                v.push_back(j);
                if (j != a[i] / j)
                    v.push_back(a[i] / j);
            }
        }
        for (int j = v.size() - 1; j >= 0; --j)
        {
            q[v[j]] += q[v[j] - 1];
            q[v[j]] %= M;
        }
    }

    int ans = 0;
    for (int i = 1; i < N * 10; ++i)
    {
        ans += q[i];
        ans %= M;
    }
    cout << ans << endl;
    return 0;
}