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
const int N = 100005;

int n;
ll a[N];
char b[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] *= 2;
    }
    cin >> (b + 1);

    ll ans = 0;

    deque<int> g, w;
    bool gg = false, ww = false;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] == 'L')
        {
            ans += a[i];
            while (!w.empty())
            {
                int x = w.back();
                if (a[x] <= a[i])
                {
                    ans += a[x] * 3;
                    a[i] -= a[x];
                    a[x] = 0;
                    w.pop_back();
                    continue;
                }
                ans += a[i] * 3;
                a[x] -= a[i];
                a[i] = 0;
                break;
            }
            if (a[i])
            {
                while (!g.empty())
                {
                    int x = g.front();
                    if (a[x] <= a[i])
                    {
                        ans += a[x] * 5;
                        a[i] -= a[x];
                        a[x] = 0;
                        g.pop_front();
                        continue;
                    }
                    ans += a[i] * 5;
                    a[x] -= a[i];
                    a[i] = 0;
                    break;
                }
            }
            if (a[i])
            {
                if (ww)
                    ans += 3 * a[i];
                else if (gg)
                    ans += 5 * a[i];
                else
                    assert(false);
            }
        }
        else if (b[i] == 'W')
        {
            ww = true;
            w.push_back(i);
        }
        else
        {
            gg = true;
            g.push_back(i);
        }
    }

    ll qw = 0;
    ll qg = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] == 'W')
        {
            qw += a[i];
        }
        else if (b[i] == 'G')
        {
            if (qw > a[i])
            {
                ans += a[i] * (3 + 1);
                qw -= a[i];
                a[i] = 0;
            }
            else
            {
                ans += qw * (3 + 1);
                a[i] -= qw;
                qw = 0;
            }
            qg += a[i];
        }
    }
    ans += ((qg / 2) * (5 + 1));
    qg %= 2;
    if (qw >= qg)
    {
        ans += qg * (5 + 1);
        qw -= qg;
        qg = 0;
    }
    ans += ((qw / 2) * (3 + 1));
    qw %= 2;

    ans += qg * 5;
    ans += qw * 3;

    cout << ans / 2 << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}