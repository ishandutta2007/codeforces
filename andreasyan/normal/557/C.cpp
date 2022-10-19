#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 202;

int n;
int a[N];
int d[N];

vector<int> v[N];
int s[N];
int sq[N], pq[N];

int q[M];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i];
        v[a[i]].push_back(d[i]);
    }
    for (int i = N - 2; i >= 1; --i)
    {
        s[i] = s[i + 1];
        sq[i] = sq[i + 1];
        for (int j = 0; j < v[i].size(); ++j)
            s[i] += v[i][j];
        sq[i] += v[i].size();
    }
    for (int i = 1; i < N; ++i)
        pq[i] = pq[i - 1] + v[i].size();

    int ans = N * M;
    for (int i = 1; i < N - 1; ++i)
    {
        if (v[i].empty())
            continue;
        int nn = n - sq[i + 1];
        int yans = s[i + 1];
        int qq = pq[i - 1] - v[i].size() + 1;
        if (qq <= 0)
        {
            ans = min(ans, yans);
            for (int j = 0; j < v[i].size(); ++j)
                q[v[i][j]]++;
            continue;
        }
        for (int j = 1; j < M; ++j)
        {
            if (qq <= q[j])
            {
                yans += (qq * j);
                break;
            }
            else
            {
                qq -= q[j];
                yans += (q[j] * j);
            }
        }
        ans = min(ans, yans);
        for (int j = 0; j < v[i].size(); ++j)
            q[v[i][j]]++;
    }
    cout << ans << endl;
    return 0;
}