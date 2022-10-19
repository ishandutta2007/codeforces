#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 5000006;

int g[N];

int z;
pair<int, int> v[13000000];
int l[N], r[N];

int n, m;
bool c[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        c[i] = false;
    }
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        c[x] = true;
    }

    priority_queue<pair<int, int> > s;
    int maxu = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (c[i])
        {
            g[i] = l[i];
            s.push(m_p(-v[l[i]].fi, i));
            maxu = max(maxu, v[l[i]].se);;
        }
    }

    int ans = m;
    while (1)
    {
        int i = -s.top().fi;
        int x = s.top().se;
        s.pop();
        ans = min(ans, maxu - i);

        ++g[x];
        if (g[x] == r[x])
        {
            break;
        }
        s.push(m_p(-v[g[x]].fi, x));
        maxu = max(maxu, v[g[x]].se);
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    g[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (g[i])
            continue;
        for (int j = i; j < N; j += i)
        {
            if (!g[j])
                g[j] = i;
        }
    }

    pair<int, int> p[102];
    int sp;
    int b[1003];
    int sb;
    pair<int, int> yv[2003];
    int syv;
    pair<int, int> vv[102];
    int svv;

    for (int i = 1; i < N; ++i)
    {
        sp = sb = 0;

        int x = i;
        while (x > 1)
        {
            if (sp == 0 || p[sp - 1].fi != g[x])
                p[sp++] = m_p(g[x], 1);
            else
                p[sp - 1].se++;
            x /= g[x];
        }

        b[sb++] = 1;
        for (int j = 0; j < sp; ++j)
        {
            int ss = sb;
            for (int k = 0; k < ss; ++k)
            {
                int x = b[k];
                for (int q = 0; q < p[j].se; ++q)
                {
                    x *= p[j].fi;
                    b[sb++] = x;
                }
            }
        }
        sort(b, b + sb);

        syv = svv = 0;
        for (int j = 0; j < sb; ++j)
        {
            if (b[j] == 1 || b[j] == i)
                continue;
            if (b[j] * 1LL * b[j] > i)
                break;
            int x = i;
            int minu = N;
            //while (x % b[j] == 0)
            {
                x /= b[j];

                int l1 = l[x], r1 = r[x] - 1;
                int u = r[x];
                while (l1 <= r1)
                {
                    int m = (l1 + r1) / 2;
                    if (v[m].fi >= b[j])
                    {
                        u = m;
                        r1 = m - 1;
                    }
                    else
                        l1 = m + 1;
                }
                if (u < r[x])
                    minu = min(minu, v[u].se);
            }
            if (minu != N)
                yv[syv++] = m_p(b[j], minu);
        }
        yv[syv++] = m_p(i, i);

        //sort(yv, yv + syv);
        int minu = N;
        for (int j = syv - 1; j >= 0; --j)
        {
            if (yv[j].se >= minu)
                continue;
            minu = yv[j].se;
            vv[svv++] = yv[j];
        }
        reverse(vv, vv + svv);

        l[i] = z;
        for (int j = 0; j < svv; ++j)
        {
            v[z++] = vv[j];
        }
        r[i] = z;
    }

    //cout << z << "\n";
    //return 0;

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}