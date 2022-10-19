#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(341);
const int N = 503;

int n;
int u[N * N];

int a[N][N];

set<pair<int, pair<int, int> > > ss;
set<pair<int, pair<int, int> > > t[N], s[N];

int stgn()
{
    ss.clear();
    for (int i = 1; i <= n; ++i)
    {
        s[i].clear();
        t[i].clear();
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            ss.insert(m_p(a[i][j], m_p(i, j)));
            t[i].insert(m_p(a[i][j], m_p(i, j)));
            s[j].insert(m_p(a[i][j], m_p(i, j)));
        }
    }
    int ans = 0;
    int i = (*ss.begin()).second.first;
    int j = (*ss.begin()).second.second;
    ss.erase(m_p(a[i][j], m_p(i, j)));
    t[i].erase(m_p(a[i][j], m_p(i, j)));
    s[j].erase(m_p(a[i][j], m_p(i, j)));
    while (1)
    {
        if (ss.empty())
            return ans;
        pair<int, pair<int, int> > minu = m_p(N * N, m_p(N, N));
        if (!t[i].empty())
            minu = min(minu, *t[i].begin());
        if (!s[j].empty())
            minu = min(minu, *s[j].begin());
        if (minu.first == N * N)
        {
            ++ans;
            i = (*ss.begin()).second.first;
            j = (*ss.begin()).second.second;
            ss.erase(m_p(a[i][j], m_p(i, j)));
            t[i].erase(m_p(a[i][j], m_p(i, j)));
            s[j].erase(m_p(a[i][j], m_p(i, j)));
        }
        else
        {
            i = minu.second.first;
            j = minu.second.second;
            ss.erase(m_p(a[i][j], m_p(i, j)));
            t[i].erase(m_p(a[i][j], m_p(i, j)));
            s[j].erase(m_p(a[i][j], m_p(i, j)));
        }
    }
}

set<pair<int, pair<int, int> > > ap[N * 10], am[N * 10];

int stgt()
{
    ss.clear();
    for (int i = 1; i <= n; ++i)
    {
        s[i].clear();
        t[i].clear();
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            ap[i + j].clear();
            am[i - j + N].clear();
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            ss.insert(m_p(a[i][j], m_p(i, j)));
            t[i].insert(m_p(a[i][j], m_p(i, j)));
            s[j].insert(m_p(a[i][j], m_p(i, j)));
            ap[i + j].insert(m_p(a[i][j], m_p(i, j)));
            am[i - j + N].insert(m_p(a[i][j], m_p(i, j)));
        }
    }
    int ans = 0;
    int i = (*ss.begin()).second.first;
    int j = (*ss.begin()).second.second;
    ss.erase(m_p(a[i][j], m_p(i, j)));
    t[i].erase(m_p(a[i][j], m_p(i, j)));
    s[j].erase(m_p(a[i][j], m_p(i, j)));
    ap[i + j].erase(m_p(a[i][j], m_p(i, j)));
    am[i - j + N].erase(m_p(a[i][j], m_p(i, j)));
    while (1)
    {
        if (ss.empty())
            return ans;
        pair<int, pair<int, int> > minu = m_p(N * N, m_p(N, N));
        if (!t[i].empty())
            minu = min(minu, *t[i].begin());
        if (!s[j].empty())
            minu = min(minu, *s[j].begin());
        if (!ap[i + j].empty())
            minu = min(minu, *ap[i + j].begin());
        if (!am[i - j + N].empty())
            minu = min(minu, *am[i - j + N].begin());
        if (minu.first == N * N)
        {
            ++ans;
            i = (*ss.begin()).second.first;
            j = (*ss.begin()).second.second;
            ss.erase(m_p(a[i][j], m_p(i, j)));
            t[i].erase(m_p(a[i][j], m_p(i, j)));
            s[j].erase(m_p(a[i][j], m_p(i, j)));
            ap[i + j].erase(m_p(a[i][j], m_p(i, j)));
            am[i - j + N].erase(m_p(a[i][j], m_p(i, j)));
        }
        else
        {
            i = minu.second.first;
            j = minu.second.second;
            ss.erase(m_p(a[i][j], m_p(i, j)));
            t[i].erase(m_p(a[i][j], m_p(i, j)));
            s[j].erase(m_p(a[i][j], m_p(i, j)));
            ap[i + j].erase(m_p(a[i][j], m_p(i, j)));
            am[i - j + N].erase(m_p(a[i][j], m_p(i, j)));
        }
    }
}

void solv()
{
    while (1)
    {
        for (int i = 1; i <= n * n; ++i)
        {
            u[i] = i;
        }
        for (int i = n * n; i >= 1; --i)
        {
            swap(u[i], u[(rnd() % i) + 1]);
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                a[i][j] = u[(i - 1) * n + j];
            }
        }
        if (stgn() < stgt())
        {
            //printf("Very good\n");
            /*for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }*/
            break;
        }
        else
        {
            //printf("Oh no. I should try again.\n");
        }
    }
}

int main()
{
    scanf("%d", &n);
    if (n <= 2)
    {
        printf("-1\n");
        return 0;
    }
    if (n <= 10)
    {
        solv();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    int nn = n;
    n = 10;
    solv();
    for (int n = 11; n <= nn; ++n)
    {
        int si, sj;
        for (int i = 1; i <= (n - 1); ++i)
        {
            for (int j = 1; j <= (n - 1); ++j)
            {
                if (a[i][j] == 1)
                {
                    si = i;
                    sj = j;
                }
                a[i][j] += (n + n - 1);
            }
        }
        int k = 1;
        int ui = -1, uj = -1;
        for (int i = 1; i < n; ++i)
        {
            if (i != si && n != sj && i + n != si + sj && i - n != si - sj)
            {
                ui = i;
                uj = n;
            }
        }
        for (int j = 1; j < n; ++j)
        {
            if (n != si && j != sj && n + j != si + sj && n - j != si - sj)
            {
                ui = n;
                uj = j;
            }
        }
        if (uj == n)
        {
            for (int j = 1; j <= n; ++j)
            {
                a[n][j] = ++k;
            }
            for (int i = 1; i < n; ++i)
            {
                if (i == ui)
                    continue;
                a[i][n] = ++k;
            }
        }
        else
        {
            for (int i = 1; i <= n; ++i)
            {
                a[i][n] = ++k;
            }
            for (int j = 1; j < n; ++j)
            {
                if (j == uj)
                    continue;
                a[n][j] = ++k;
            }
        }
        a[ui][uj] = 1;
    }
    n = nn;
    //assert(stgn() < stgt());
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}