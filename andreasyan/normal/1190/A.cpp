#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

long long n;
long long m, k;
long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    queue<long long> q;
    for (int i = 0; i < m; ++i)
    {
        long long x;
        cin >> x;
        q.push(x);
    }
    long long num = 0;
    long long ans = 0;
    while (!q.empty())
    {
        long long x = q.front();
        q.pop();
        long long pnum = 1;
        while (!q.empty() && (x - num - 1) / k == (q.front() - num - 1) / k)
        {
            q.pop();
            pnum++;
        }
        num += pnum;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}