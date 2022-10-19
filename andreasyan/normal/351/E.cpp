#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2003, M = 100005;

int n;
int a[N];

vector<int> v[M];

int t[N];

void ubd(int x, int y)
{
    while (x <= n)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int l, int r)
{
    int ans = 0;
    while (r)
    {
        ans += t[r];
        r -= (r & (-r));
    }
    --l;
    while (l)
    {
        ans -= t[l];
        l -= (l & (-l));
    }
    return ans;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < 0)
            a[i] *= (-1);
        v[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        ubd(i, 1);
    int ans = 0;
    for (int x = M - 1; x >= 0; --x)
    {
        for (int j = 0; j < v[x].size(); ++j)
        {
            int i = v[x][j];
            ubd(i, -1);
        }
        int yans = 0;
        for (int j = 0; j < v[x].size(); ++j)
        {
            int i = v[x][j];
            yans += qry(i, n);
        }
        int minu = yans;
        for (int j = 0; j < v[x].size(); ++j)
        {
            int i = v[x][j];
            yans -= qry(i, n);
            yans += qry(1, i);
            minu = min(minu, yans);
        }
        ans += minu;
    }
    printf("%d\n", ans);
    return 0;
}