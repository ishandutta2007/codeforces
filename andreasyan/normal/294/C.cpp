#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
const long long M = 1000000007;

int n, q;
bool c[N];

long long z[N][N];
void pre()
{
    for (int i = 0; i <= n; ++i)
    {
        z[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            z[i][j] = (z[i - 1][j - 1] + z[i - 1][j]) % M;
    }
}

vector<int> v;

long long dp[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    while (q--)
    {
        int x;
        cin >> x;
        c[x] = true;
    }
    pre();

    q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
        {
            v.push_back(q);
            q = 0;
        }
        else
        {
            ++q;
        }
    }

    dp[0] = 1;
    int p = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        p += v[i];
        long long t = 0;
        for (int j = 0; j < v[i]; ++j)
        {
            t = (t + z[v[i] - 1][j]) % M;
        }
        if (v[i] == 0)
            t = 1;
        dp[i] = (((dp[i - 1] * t) % M) * z[p][v[i]]) % M;
    }

    cout << (dp[v.size() - 1] * z[n - v.size()][q]) % M << endl;
    return 0;
}