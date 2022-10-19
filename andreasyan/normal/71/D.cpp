#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 23;
const char M[N] = {'C', 'D', 'H', 'S'};
const char P[N] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

int n, m;
pair<char, char> a[N][N];

pair<pair<int, int>, pair<int, int> > stg()
{
    for (int i = 1; i <= n - 3 + 1; ++i)
    {
        for (int j = 1; j <= m - 3 + 1; ++j)
        {
            set<char> f, s;
            for (int ii = i; ii <= i + 3 - 1; ++ii)
            {
                for (int jj = j; jj <= j + 3 - 1; ++jj)
                {
                    f.insert(a[ii][jj].first);
                    s.insert(a[ii][jj].second);
                }
            }
            if (f.size() == 9 || s.size() == 1)
            {
                for (int i1 = 1; i1 <= n - 3 + 1; ++i1)
                {
                    for (int j1 = 1; j1 <= m - 3 + 1; ++j1)
                    {
                        if (max(i, i1) <= min(i + 3 - 1, i1 + 3 - 1) && max(j, j1) <= min(j + 3 - 1, j1 + 3 - 1))
                            continue;
                        set<int> s, f;
                        for (int ii = i1; ii <= i1 + 3 - 1; ++ii)
                        {
                            for (int jj = j1; jj <= j1 + 3 - 1; ++jj)
                            {
                                f.insert(a[ii][jj].first);
                                s.insert(a[ii][jj].second);
                            }
                        }
                        if (f.size() == 9 || s.size() == 1)
                            return m_p(m_p(i, j), m_p(i1, j1));
                    }
                }
            }
        }
    }
    return m_p(m_p(0, 0), m_p(0, 0));
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            scanf(" %c %c", &a[i][j].first, &a[i][j].second);
    }
    set<pair<char, char> > s;
    for (int i = 0; i < 13; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            s.insert(m_p(P[i], M[j]));
        }
    }
    vector<pair<int, int> > vv;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s.find(a[i][j]) != s.end())
                s.erase(a[i][j]);
            if (a[i][j].second == '1' || a[i][j].second == '2')
                vv.push_back(m_p(i, j));
        }
    }
    if (vv.size() == 2)
    {
        if (a[vv[0].first][vv[0].second].second == '2')
            swap(vv[0], vv[1]);
    }
    vector<pair<char, char> > v;
    for (set<pair<char, char> >::iterator it = s.begin(); it != s.end(); ++it)
        v.push_back(*it);
    if (vv.empty())
    {
        pair<pair<int, int>, pair<int, int> > u = stg();
        if (!u.first.first)
        {
            printf("No solution.\n");
        }
        else
        {
            printf("Solution exists.\n");
            printf("There are no jokers.\n");
            printf("Put the first square to (%d, %d).\n", u.first.first, u.first.second);
            printf("Put the second square to (%d, %d).\n", u.second.first, u.second.second);
        }
    }
    else if (vv.size() == 1)
    {
        pair<char, char> o = a[vv[0].first][vv[0].second];
        for (int i = 0; i < v.size(); ++i)
        {
            a[vv[0].first][vv[0].second] = v[i];
            pair<pair<int, int>, pair<int, int> > u = stg();
            if (u.first.first)
            {
                printf("Solution exists.\n");
                printf("Replace %c%c with %c%c.\n", o.first, o.second, v[i].first, v[i].second);
                printf("Put the first square to (%d, %d).\n", u.first.first, u.first.second);
                printf("Put the second square to (%d, %d).\n", u.second.first, u.second.second);
                return;
            }
        }
        printf("No solution.\n");
    }
    else
    {
        for (int i = 0; i < v.size(); ++i)
        {
            a[vv[0].first][vv[0].second] = v[i];
            for (int j = 0; j < v.size(); ++j)
            {
                if (i == j)
                    continue;
                a[vv[1].first][vv[1].second] = v[j];
                pair<pair<int, int>, pair<int, int> > u = stg();
                if (u.first.first)
                {
                    printf("Solution exists.\n");
                    printf("Replace J1 with %c%c and J2 with %c%c.\n", v[i].first, v[i].second, v[j].first, v[j].second);
                    printf("Put the first square to (%d, %d).\n", u.first.first, u.first.second);
                    printf("Put the second square to (%d, %d).\n", u.second.first, u.second.second);
                    return;
                }
            }
        }
        printf("No solution.\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}