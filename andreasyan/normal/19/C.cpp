#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
int P, P1;

bool stg(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if ((x % i == 0))
            return false;
    }
    return true;
}

int n;
int a[N];

int ast[N];
int p[N];

int ast1[N];
int p1[N];

void pre()
{
    P = rnd() % 1000000000;
    while (!stg(P))
        ++P;
    while (1)
    {
        P1 = rnd() % 1000000000;
        while (!stg(P1))
            ++P1;
        if (P1 != P)
            break;
    }
    ast[0] = 1;
    for (int i = 1; i <= n; ++i)
        ast[i] = ast[i - 1] * P;
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + ast[i] * a[i];
    ast1[0] = 1;
    for (int i = 1; i <= n; ++i)
        ast1[i] = ast1[i - 1] * P1;
    for (int i = 1; i <= n; ++i)
        p1[i] = p1[i - 1] + ast1[i] * a[i];
}

map<int, vector<int> > mp;

bool so(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second - a.first < b.second - b.first)
        return true;
    if (a.second - a.first > b.second - b.first)
        return false;
    return a.first < b.first;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        mp[a[i]].push_back(i);
    }
    pre();
    vector<pair<int, int> > vv;
    for (map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        vector<int> v = it->second;
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = i + 1; j < v.size(); ++j)
            {
                int l1 = v[i];
                int r1 = v[j] - 1;
                int l2 = v[j];
                int r2 = l2 + (r1 - l1);
                if (r2 > n)
                    break;
                int h1 = p[r1] - p[l1 - 1];
                int h2 = p[r2] - p[l2 - 1];
                h1 *= ast[r2 - r1];
                int h11 = p1[r1] - p1[l1 - 1];
                int h21 = p1[r2] - p1[l2 - 1];
                h11 *= ast1[r2 - r1];
                if (h1 == h2 && h11 == h21)
                    vv.push_back(m_p(l1, r1));
            }
        }
    }
    sort(vv.begin(), vv.end(), so);
    int u = 0;
    for (int i = 0; i < vv.size(); ++i)
    {
        int l = vv[i].first;
        int r = vv[i].second;
        if (l <= u)
            continue;
        u = r;
    }
    printf("%d\n", n - u);
    for (int i = u + 1; i <= n; ++i)
        printf("%d ", a[i]);
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