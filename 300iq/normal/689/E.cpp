#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;
const int M = 1e9 + 7;

int fact[N];
int rfact[N];

int bin(int a, int n)
{
    if (!n)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        int t = bin(a, n / 2);
        return (t * (ll) t) % M;
    }
    else
    {
        return (a * (ll) bin(a, n - 1)) % M;
    }
}

int C(int n, int k)
{
    if (n < k)
    {
        return 0;
    }
    return ((fact[n] * (ll) rfact[k]) % M * (ll) rfact[n - k]) % M;
}


int main()
{
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * (ll) i) % M;
        rfact[i] = bin(fact[i], M - 2);
    }
    vector <int> t;
    vector <pair <int, int> > e;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        e.push_back({l, r});
        t.push_back(l + 1);
        t.push_back(r + 1);
        t.push_back(l - 1);
        t.push_back(r - 1);
        t.push_back(l);
        t.push_back(r);
    }
    int cnt = 0;
    priority_queue <int, vector <int>, greater <int> > s;
    sort(e.begin(), e.end());
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    int m = t.size();
    int j = -1;
    int ans = 0;
    for (int i = 0; i < m - 1; i++)
    {
        while (j + 1 < n && e[j + 1].first <= t[i])
        {
            s.push(e[j + 1].second);
            j++;
        }
        while (!s.empty() && s.top() < t[i + 1] - 1)
        {
            s.pop();
        }
        int cnt = s.size();
        int add = (C(cnt, k) * (ll) (t[i + 1] - t[i])) % M;
        ans = (ans + add) % M;
    }
    printf("%d\n", ans);
}