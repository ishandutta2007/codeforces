/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <int> g[2][2];

struct mega_set
{
    priority_queue <int> q;
    priority_queue <int, vector <int>, greater <int> > d;
    ll sum = 0;
    mega_set()
    {
    }
    void insert(int x)
    {
        q.push(x);
        sum += x;
    }
    void erase(int x)
    {
        //if we will use set, it will be possible
    }
    void relax()
    {
        while (!q.empty() && !d.empty() && d.top() < q.top())
        {
            sum -= q.top();
            sum += d.top();
            q.push(d.top());
            d.push(q.top());
            d.pop();
            q.pop();
        }
    }
    void fit(int k)
    {
        while (q.size() > k)
        {
            sum -= q.top();
            d.push(q.top());
            q.pop();
        }
        while (q.size() < k)
        {
            sum += d.top();
            q.push(d.top());
            d.pop();
        }
        relax();
    }
    int get(int k)
    {
        fit(k);
        return q.top();
    }
    ll sum_get(int k)
    {
        fit(k);
        return sum;
    }
    int size()
    {
        return q.size() + d.size();
    }
};

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector <bool> a(n), b(n);
    vector <int> c(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }
    int x;
    scanf("%d", &x);
    while (x--)
    {
        int i;
        scanf("%d", &i);
        i--;
        a[i] = 1;
    }
    scanf("%d", &x);
    while (x--)
    {
        int i;
        scanf("%d", &i);
        i--;
        b[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        g[a[i]][b[i]].push_back(c[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sort(g[i][j].begin(), g[i][j].end()); 
        }
    }
    ll s = 0;
    for (auto c : g[0][1])
    {
        s += c;
    }
    for (auto c : g[1][0])
    {
        s += c;
    }
    mega_set pr;
    for (auto c : g[0][0])
    {
        pr.insert(c);
    }
    g[1][1].push_back(0);
    int n_a = k, n_b = k;
    ll res = 1e18;
    int cnt = (int) g[0][1].size() + (int) g[1][0].size();
    for (auto c : g[1][1])
    {
        while (g[0][1].size() > n_a)
        {
            cnt--;
            s -= g[0][1].back();
            pr.insert(g[0][1].back());
            g[0][1].pop_back();
        }
        while (g[1][0].size() > n_b)
        {
            cnt--;
            s -= g[1][0].back();
            pr.insert(g[1][0].back());
            g[1][0].pop_back();
        }
        if (g[0][1].size() >= n_a && g[1][0].size() >= n_b && pr.size() >= m - cnt && m - cnt >= 0)
        {
            res = min(res, s + pr.sum_get(m - cnt));
        }
        s += c; 
        cnt++;
        n_a--, n_b--;
        n_a = max(n_a, 0);
        n_b = max(n_b, 0);
    }
    if (res == 1e18)
    {
        res = -1;
    }
    printf("%lld\n", res);
}