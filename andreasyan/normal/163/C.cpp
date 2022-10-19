#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, l, v1, v2;
vector<pair<double, int> > v;

double ans[N];

void solv()
{
    scanf("%d%d%d%d", &n, &l, &v1, &v2);
    double d = (v2 * 1LL * l) / (v1 + v2 + 0.0);
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        double y = x - d;
        v.push_back(m_p(x, 1));
        if (y >= 0)
            v.push_back(m_p(y, -1));
        else
        {
            ++s;
            v.push_back(m_p(y + 2 * l, -1));
        }
    }
    sort(v.begin(), v.end());
    double u = 2 * l;
    for (int i = (int)v.size() - 1; i >= 0; --i)
    {
        ans[s] += (u - v[i].first);
        u = v[i].first;
        s += v[i].second;
    }
    ans[s] += u;
    for (int i = 0; i <= n; ++i)
    {
        ans[i] /= (2 * l);
        printf("%.12f\n", ans[i]);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}