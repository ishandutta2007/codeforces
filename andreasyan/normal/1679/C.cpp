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

int n, qq;

int s[N], t[N];

void ubd(int t[], int x, int y)
{
    while (x <= n)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int t[], int l, int r)
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

int qs[N], qt[N];

void solv()
{
    cin >> n >> qq;

    while (qq--)
    {
        int ty;
        cin >> ty;

        if (ty == 1)
        {
            int x, y;
            cin >> x >> y;

            ++qt[x];
            ++qs[y];

            if (qt[x] == 1)
                ubd(t, x, 1);
            if (qs[y] == 1)
                ubd(s, y, 1);
        }
        else if (ty == 2)
        {
            int x, y;
            cin >> x >> y;

            --qt[x];
            --qs[y];

            if (qt[x] == 0)
                ubd(t, x, -1);
            if (qs[y] == 0)
                ubd(s, y, -1);
        }
        else
        {
            int x1, y1_, x2, y2;
            cin >> x1 >> y1_ >> x2 >> y2;

            if (qry(t, x1, x2) == x2 - x1 + 1 || qry(s, y1_, y2) == y2 - y1_ + 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}