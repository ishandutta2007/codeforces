#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 202, K = 6;

bool c[N][N][K][K];
vector<pair<int, int> > h[N][N][K][K];

void pre()
{
    c[0][0][0][0] = true;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 1; k <= 5; ++k)
            {
                for (int g = 0; g <= k; ++g)
                {
                    int w;
                    if (k <= 4)
                    {
                        w = 25;
                    }
                    else
                    {
                        w = 15;
                    }
                    for (int p = 0; p < w - 1; ++p)
                    {
                        if (i - p >= 0 && j - w >= 0 && c[i - p][j - w][k - 1][g] && (k - 1 - g) != 3 && g != 3)
                        {
                            c[i][j][k][g] = true;
                            h[i][j][k][g] = h[i - p][j - w][k - 1][g];
                            h[i][j][k][g].push_back(m_p(p, w));
                        }
                        swap(p, w);
                        if (i - p >= 0 && j - w >= 0 && g > 0 && c[i - p][j - w][k - 1][g - 1] && (k - 1 - (g - 1)) != 3 && (g - 1) != 3)
                        {
                            c[i][j][k][g] = true;
                            h[i][j][k][g] = h[i - p][j - w][k - 1][g - 1];
                            h[i][j][k][g].push_back(m_p(p, w));
                        }
                        swap(p, w);
                    }
                    for (int p = w - 1; p + 2 <= max(i, j); ++p)
                    {
                        w = p + 2;
                        if (i - p >= 0 && j - w >= 0 && c[i - p][j - w][k - 1][g] && (k - 1 - g) != 3 && g != 3)
                        {
                            c[i][j][k][g] = true;
                            h[i][j][k][g] = h[i - p][j - w][k - 1][g];
                            h[i][j][k][g].push_back(m_p(p, w));
                        }
                        swap(p, w);
                        if (i - p >= 0 && j - w >= 0 && g > 0 && c[i - p][j - w][k - 1][g - 1] && (k - 1 - (g - 1)) != 3 && (g - 1) != 3)
                        {
                            c[i][j][k][g] = true;
                            h[i][j][k][g] = h[i - p][j - w][k - 1][g - 1];
                            h[i][j][k][g].push_back(m_p(p, w));
                        }
                        swap(p, w);
                    }
                }
            }
        }
    }
}

void solv()
{
    int i, j;
    scanf("%d%d", &i, &j);
    int maxu = -10;
    vector<pair<int, int> > hh;
    for (int k = 0; k <= 5; ++k)
    {
        for (int g = 0; g <= k; ++g)
        {
            if (c[i][j][k][g] && (g == 3 || (k - g) == 3))
            {
                if (g - (k - g) > maxu)
                {
                    maxu = g - (k - g);
                    hh = h[i][j][k][g];
                }
            }
        }
    }
    if (maxu == -10)
    {
        printf("Impossible\n");
        return;
    }
    int k = hh.size();
    int g = 0;
    for (int i = 0; i < hh.size(); ++i)
    {
        if (hh[i].first > hh[i].second)
            ++g;
    }
    printf("%d:%d\n", g, (k - g));
    for (int i = 0; i < hh.size(); ++i)
        printf("%d:%d ", hh[i].first, hh[i].second);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}