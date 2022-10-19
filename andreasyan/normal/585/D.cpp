#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 26, INF = 1000000009;

int n;
int l[N], m[N], w[N];

map<pair<int, int>, int> maxu;
map<pair<int, int>, pair<int, int> > maxi;

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &l[i], &m[i], &w[i]);
    for (int x = 0; x < (1 << (n / 2)); ++x)
    {
        for (int y = x; ; y = (y - 1) & x)
        {
            int ll = 0, mm = 0, ww = 0;
            for (int i = 0; i < (n / 2); ++i)
            {
                if (!(x & (1 << i)))
                {
                    mm += m[i];
                    ww += w[i];
                }
                else
                {
                    if (!(y & (1 << i)))
                    {
                        ll += l[i];
                        ww += w[i];
                    }
                    else
                    {
                        ll += l[i];
                        mm += m[i];
                    }
                }
            }
            if (maxu.find(m_p(mm - ll, ww - ll)) == maxu.end() || maxu[m_p(mm - ll, ww - ll)] < ll)
            {
                maxu[m_p(mm - ll, ww - ll)] = ll;
                maxi[m_p(mm - ll, ww - ll)] = m_p(x, y);
            }
            if (y == 0)
                break;
        }
    }
    int ans = -INF;
    int ansx, ansy;
    for (int x = 0; x < (1 << (n / 2 + n % 2)); ++x)
    {
        for (int y = x; ; y = (y - 1) & x)
        {
            int ll = 0, mm = 0, ww = 0;
            for (int i = 0; i < (n / 2 + n % 2); ++i)
            {
                if (!(x & (1 << i)))
                {
                    mm += m[i + n / 2];
                    ww += w[i + n / 2];
                }
                else
                {
                    if (!(y & (1 << i)))
                    {
                        ll += l[i + n / 2];
                        ww += w[i + n / 2];
                    }
                    else
                    {
                        ll += l[i + n / 2];
                        mm += m[i + n / 2];
                    }
                }
            }
            if (maxu.find(m_p(ll - mm, ll - ww)) != maxu.end())
            {
                if (maxu[m_p(ll - mm, ll - ww)] + ll > ans)
                {
                    ans = maxu[m_p(ll - mm, ll - ww)] + ll;
                    ansx = maxi[m_p(ll - mm, ll - ww)].first | (x << (n / 2));
                    ansy = maxi[m_p(ll - mm, ll - ww)].second | (y << (n / 2));
                }
            }
            if (y == 0)
                break;
        }
    }
    if (ans == -INF)
    {
        printf("Impossible\n");
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!(ansx & (1 << i)))
        {
            printf("MW\n");
        }
        else
        {
            if (!(ansy & (1 << i)))
            {
                printf("LW\n");
            }
            else
            {
                printf("LM\n");
            }
        }
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