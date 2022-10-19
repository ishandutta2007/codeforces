#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 400005;

int n;
int a[N];

map<int, int> q;
int qq[N];

int ans, ansx, ansy;

int** yans;

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        q[a[i]]++;
    }
    for (map<int, int>::iterator it = q.begin(); it != q.end(); ++it)
    {
        qq[it->second]++;
    }
    int s = n;
    int ms = 0;
    for (int x = n; x >= 1; --x)
    {
        s -= ms;
        assert(s >= 1);
        int l = x, r = n;
        while (l <= r)
        {
            int y = (l + r) / 2;
            if (x * 1LL * y <= s)
            {
                if (x * y > ans)
                {
                    ans = x * y;
                    ansx = x;
                    ansy = y;
                }
                l = y + 1;
            }
            else
                r = y - 1;
        }
        ms += qq[x];
    }
    assert(ans >= 1);
    printf("%d\n", ans);
    printf("%d %d\n", ansx, ansy);
    vector<int> v;
    for (map<int, int>::iterator it = q.begin(); it != q.end(); ++it)
    {
        int q = min(it->second, ansx);
        if (q == ansx)
        {
            while (q--)
            {
                v.push_back(it->first);
            }
        }
    }
    for (map<int, int>::iterator it = q.begin(); it != q.end(); ++it)
    {
        int q = min(it->second, ansx);
        if (q < ansx)
        {
            while (q--)
            {
                v.push_back(it->first);
            }
        }
    }
    yans = new int*[ansx + 5];
    for (int i = 0; i < ansx + 5; ++i)
        yans[i] = new int[ansy + 5];
    int k = 0;
    for (int j = 0; j < ansy; ++j)
    {
        int y = j;
        for (int x = 0; x < ansx; ++x)
        {
            yans[x][y] = v[k++];
            y = (y + 1) % ansy;
        }
    }
    for (int i = 0; i < ansx; ++i)
    {
        for (int j = 0; j < ansy; ++j)
        {
            printf("%d ", yans[i][j]);
        }
        printf("\n");
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