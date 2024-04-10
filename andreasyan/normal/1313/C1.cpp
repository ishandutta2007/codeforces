#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 500005;

int n;
int a[N];

long long p[N], s[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        p[i] += a[i];
        int q = 1;
        while (!v.empty() && v.back().first > a[i])
        {
            p[i] -= (v.back().first - a[i]) * 1LL * v.back().second;
            q += v.back().second;
            v.pop_back();
        }
        v.push_back(m_p(a[i], q));
    }
    v.clear();
    for (int i = n; i >= 1; --i)
    {
        s[i] = s[i + 1];
        s[i] += a[i];
        int q = 1;
        while (!v.empty() && v.back().first > a[i])
        {
            s[i] -= (v.back().first - a[i]) * 1LL * v.back().second;
            q += v.back().second;
            v.pop_back();
        }
        v.push_back(m_p(a[i], q));
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, s[i] + p[i] - a[i]);
    }
    for (int j = 1; j <= n; ++j)
    {
        if (s[j] + p[j] - a[j] == ans)
        {
            vector<pair<int, int> > v;
            for (int i = 1; i <= j; ++i)
            {
                int q = 1;
                while (!v.empty() && v.back().first > a[i])
                {
                    q += v.back().second;
                    v.pop_back();
                }
                v.push_back(m_p(a[i], q));
            }
            int z = 1;
            for (int i = 0; i < v.size(); ++i)
            {
                for (int j = 0; j < v[i].second; ++j)
                {
                    a[z++] = v[i].first;
                }
            }
            v.clear();
            for (int i = n; i >= j; --i)
            {
                int q = 1;
                while (!v.empty() && v.back().first > a[i])
                {
                    q += v.back().second;
                    v.pop_back();
                }
                v.push_back(m_p(a[i], q));
            }
            z = n;
            for (int i = 0; i < v.size(); ++i)
            {
                for (int j = 0; j < v[i].second; ++j)
                {
                    a[z--] = v[i].first;
                }
            }
            for (int i = 1; i <= n; ++i)
                printf("%d ", a[i]);
            printf("\n");
            return 0;
        }
    }
    return 0;
}