#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int n, k;
long long s[N], d[N];

long long ans[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> s[i] >> d[i];

    priority_queue<long long> pq;
    for (int i = 1; i <= n; ++i)
    {
        if (pq.size() < k)
        {
            ans[i] = s[i] + d[i];
            pq.push(-ans[i]);
        }
        else
        {
            ans[i] = max(-pq.top(), s[i]) + d[i];
            pq.pop();
            pq.push(-ans[i]);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << endl;
    return 0;
}