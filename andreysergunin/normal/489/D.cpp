#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, u, v, p[10000], i, j, w, k[10000], ans;
    vector<long long> edge[10000];
    cin >> n >> m;
    for (i = 0; i < n; i++)
        k[i] = 0;
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;
        edge[u - 1].push_back(v - 1);
        k[u - 1]++;
    }
    ans = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            p[j] = 0;
        for (j = 0; j < k[i]; j++)
        {
            for (w = 0; w < k[edge[i][j]]; w++)
                if (edge[edge[i][j]][w] != i)
                {
                    p[edge[edge[i][j]][w]]++;
                }
        }
        for (j = 0; j < n; j++)
            ans += p[j] * (p[j] - 1) / 2;
    }
    cout << ans;
    return 0;
}