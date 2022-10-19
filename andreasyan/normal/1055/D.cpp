#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 3003;

int n;
char a[N][N], b[N][N];

char ll[N], rr[N];

char c[N + N];
int z[N + N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    for (int i = 0; i < n; ++i)
        scanf(" %s", b[i]);
    int u = -1, ul = -1, ur = -1;
    for (int i = 0; i < n; ++i)
    {
        int l = -1;
        for (int j = 0; j < strlen(a[i]); ++j)
        {
            if (a[i][j] != b[i][j])
            {
                l = j;
                break;
            }
        }
        if (l == -1)
            continue;
        int r = -1;
        for (int j = strlen(a[i]) - 1; j >= 0; --j)
        {
            if (a[i][j] != b[i][j])
            {
                r = j;
                break;
            }
        }
        if (u == -1)
        {
            u = i;
            ul = l;
            ur = r;
        }
        else
        {
            if (r - l + 1 != ur - ul + 1)
            {
                printf("NO\n");
                return;
            }
            for (int j = l, k = ul; j <= r; ++j, ++k)
            {
                if (a[i][j] != a[u][k] || b[i][j] != b[u][k])
                {
                    printf("NO\n");
                    return;
                }
            }
        }
        for (int j = l - 1, k = 0; j >= 0; --j, ++k)
        {
            if (ll[k] == 'Z')
                break;
            if (ll[k] == 0 || ll[k] == a[i][j])
                ll[k] = a[i][j];
            else
            {
                ll[k] = 'Z';
                break;
            }
        }
        ll[l] = 'Z';
        for (int j = r + 1, k = 0; j < strlen(a[i]); ++j, ++k)
        {
            if (rr[k] == 'Z')
                break;
            if (rr[k] == 0 || rr[k] == a[i][j])
                rr[k] = a[i][j];
            else
            {
                rr[k] = 'Z';
                break;
            }
        }
        rr[strlen(a[i]) - r - 1] = 'Z';
    }
    deque<char> s, t;
    for (int j = ul; j <= ur; ++j)
    {
        s.push_back(a[u][j]);
        t.push_back(b[u][j]);
    }
    for (int j = 0; ; ++j)
    {
        if (rr[j] == 'Z')
            break;
        s.push_back(rr[j]);
        t.push_back(rr[j]);
    }
    for (int j = 0; ; ++j)
    {
        if (ll[j] == 'Z')
            break;
        s.push_front(ll[j]);
        t.push_front(ll[j]);
    }
    int ss = s.size();
    int m = 0;
    for (int j = 0; j < ss; ++j)
        c[m++] = s[j];
    c[m++] = '#';
    for (int i = 0; i < n; ++i)
    {
        int as = strlen(a[i]);
        m = ss + 1;
        for (int j = 0; j < as; ++j)
            c[m++] = a[i][j];
        c[m] = 0;
        int l = 0, r = 0;
        for (int j = 0; j < m; ++j)
            z[j] = 0;
        for (int j = 1; j < m; ++j)
        {
            if (j <= r)
            {
                z[j] = min(r - j + 1, z[j - l]);
            }
            while (c[z[j]] == c[j + z[j]])
                ++z[j];
            if (j + z[j] - 1 > r)
            {
                l = j;
                r = j + z[j] - 1;
            }
            if (z[j] == ss)
                break;
            if (z[j] + ss - 1 >= m)
                break;
        }
        for (int j = 0; j < as; ++j)
        {
            if (j + ss - 1 >= as)
                break;
            if (z[j + ss + 1] == ss)
            {
                for (int k = j, kk = 0; k <= j + ss - 1; ++k, ++kk)
                    a[i][k] = t[kk];
                break;
            }
        }
        for (int j = 0; j < as; ++j)
        {
            if (a[i][j] != b[i][j])
            {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    for (int i = 0; i < ss; ++i)
        putchar(s[i]);
    putchar('\n');
    for (int i = 0; i < ss; ++i)
        putchar(t[i]);
    putchar('\n');
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}