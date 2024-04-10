#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, k;
int a[N];
char b[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    long long ans = 0;

    priority_queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1 || b[i] == b[i - 1])
            q.push(a[i]);
        else
        {
            for (int j = 0; j < k; ++j)
            {
                if (q.empty())
                    break;
                ans += q.top();
                q.pop();
            }
            while (!q.empty())
                q.pop();
            q.push(a[i]);
        }
    }
    for (int j = 0; j < k; ++j)
    {
        if (q.empty())
            break;
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}