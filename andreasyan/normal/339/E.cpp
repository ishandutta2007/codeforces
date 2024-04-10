#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1003;

int n;
int a[N];

vector<pair<int, int> > g;

bool rec()
{
    bool z = true;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != i)
        {
            z = false;
            break;
        }
    }
    if (z)
    {
        printf("%d\n", g.size());
        for (int i = (int)g.size() - 1; i >= 0; --i)
        {
            printf("%d %d\n", g[i].first, g[i].second);
        }
        return true;
    }
    if (g.size() == 3)
        return false;
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1 || i == n || abs(a[i - 1] - a[i]) != 1 || abs(a[i + 1] - a[i]) != 1)
            v.push_back(i);
    }
    for (int ll = 0; ll < v.size(); ++ll)
    {
        for (int rr = ll + 1; rr < v.size(); ++rr)
        {
            int l = v[ll];
            int r = v[rr];
            reverse(a + l, a + r + 1);
            g.push_back(m_p(l, r));
            if (rec())
                return true;
            reverse(a + l, a + r + 1);
            g.pop_back();
        }
    }
    return false;
}

void solv()
{
    g.clear();
    if (rec())
        return;
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    exit(0);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    /*while (1)
    {
        n = 6;
        for (int i = 1; i <= n; ++i)
            a[i] = i;
        for (int i = 0; i < 3; ++i)
        {
            int l = rnf() % n + 1;
            int r = rnf() % n + 1;
            if (l > r)
                swap(l, r);
            reverse(a + l, a + r + 1);
        }
        solv();
    }*/
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}