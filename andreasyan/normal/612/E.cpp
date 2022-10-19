#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;

int n;
int a[N];
bool c[N];

int ans[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<pair<int, vector<int> > > vv;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        vector<int> v;
        int x = i;
        while (1)
        {
            v.push_back(x);
            c[x] = true;
            if (c[a[x]])
                break;
            x = a[x];
        }
        if (v.size() % 2 == 1)
        {
            vector<int> u(v.size());
            int j = 0;
            for (int i = 0; i < v.size(); i += 2)
                u[i] = v[j++];
            for (int i = 1; i < v.size(); i += 2)
                u[i] = v[j++];
            for (int i = 0; i < (int)u.size() - 1; ++i)
                ans[u[i]] = u[i + 1];
            ans[u.back()] = u[0];
        }
        else
        {
            vv.push_back(m_p(v.size(), v));
        }
    }
    sort(vv.begin(), vv.end());
    for (int i = 0; i < vv.size(); ++i)
    {
        int ii = vv.size();
        for (int j = i; j < vv.size(); ++j)
        {
            if (vv[j].first != vv[i].first)
            {
                ii = j;
                break;
            }
        }
        if ((ii - i) % 2 == 1)
        {
            printf("-1\n");
            return;
        }
        for (int j = i; j < ii; j += 2)
        {
            vector<int> u;
            for (int k = 0; k < vv[j].first; ++k)
            {
                u.push_back(vv[j].second[k]);
                u.push_back(vv[j + 1].second[k]);
            }
            for (int i = 0; i < (int)u.size() - 1; ++i)
                ans[u[i]] = u[i + 1];
            ans[u.back()] = u[0];
        }
        i = ii - 1;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
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