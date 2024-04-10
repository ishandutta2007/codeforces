#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
long long k;
int a[N];

int main()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    deque<int> q;
    for (int i = 1; i <= n; ++i)
        q.push_back(a[i]);
    int minq = 0, maxq = 0;
    int minu = q.front();
    int maxu = q.back();
    while (!q.empty() && q.front() == minu)
    {
        minq++;
        q.pop_front();
    }
    while (!q.empty() && q.back() == maxu)
    {
        maxq++;
        q.pop_back();
    }
    while (1)
    {
        if (q.empty())
            break;
        if (minq < maxq)
        {
            long long u = q.front() - minu;
            if (u * minq <= k)
            {
                k -= u * minq;
                minu = q.front();
            }
            else
            {
                cout << (maxu - minu) - (k / minq) << endl;
                return 0;
            }
        }
        else
        {
            long long u = maxu - q.back();
            if (u * maxq <= k)
            {
                k -= u * maxq;
                maxu = q.back();
            }
            else
            {
                cout << (maxu - minu) - (k / maxq) << endl;
                return 0;
            }
        }
        while (!q.empty() && q.front() == minu)
        {
            minq++;
            q.pop_front();
        }
        while (!q.empty() && q.back() == maxu)
        {
            maxq++;
            q.pop_back();
        }
    }
    if (minq < maxq)
    {
        long long u = (maxu - minu);
        if (k >= u * minq)
            cout << 0 << endl;
        else
            cout << (maxu - minu) - (k / minq) << endl;
    }
    else
    {
        long long u = (maxu - minu);
        if (k >= u * maxq)
            cout << 0 << endl;
        else
            cout << (maxu - minu) - (k / maxq) << endl;
    }
    return 0;
}