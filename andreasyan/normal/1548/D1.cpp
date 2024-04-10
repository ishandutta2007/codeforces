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
const int N = 6003;

struct ban
{
    int x, y;
    ban(){}
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

ll stg(ban t1, ban t2, ban t)
{
    return (t.x - t1.x) * 1LL * (t2.y - t1.y) - (t.y - t1.y) * 1LL * (t2.x - t1.x);
}

int nsh(ll x)
{
    if (x < 0)
        return -1;
    if (x > 0)
        return 1;
    return 0;
}

/* A utility function to calculate area of triangle formed by (x1, y1),
   (x2, y2) and (x3, y3) */
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3);

   /* Calculate area of triangle PBC */
   float A1 = area (x, y, x2, y2, x3, y3);

   /* Calculate area of triangle PAC */
   float A2 = area (x1, y1, x, y, x3, y3);

   /* Calculate area of triangle PAB */
   float A3 = area (x1, y1, x2, y2, x, y);

   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}

void por()
{
    ban t1;
    ban t2;

    cin >> t1.x >> t1.y;
    cin >> t2.x >> t2.y;

    ban t;
    for (t.x = 0; t.x <= 30; t.x += 2)
    {
        for (t.y = 0; t.y <= 30; t.y += 2)
        {
            if (stg(t1, t2, t) == 0)
                continue;
            int q = 0;
            for (int x = 0; x <= 30; ++x)
            {
                for (int y = 0; y <= 30; ++y)
                {
                    //if (nsh(stg(t1, t2, ban(x, y))) == nsh(stg(t2, t, ban(x, y))) && nsh(stg(t2, t, ban(x, y))) == nsh(stg(t, t1, ban(x, y))))
                    if (isInside(t1.x, t1.y, t2.x, t2.y, t.x, t.y, x, y))
                        ++q;
                }
            }
            if (q % 2 == 1)
            {
                //cout << t.x << ' ' << t.y << "\n";
                //continue;
                cout << abs(t1.x - t2.x) / 2 % 2 << ' ';
                cout << abs(t1.y - t2.y) / 2 % 2 << ' ';
                cout << abs(t2.x - t.x) / 2 % 2 << ' ';
                cout << abs(t2.y - t.y) / 2 % 2 << ' ';
                cout << "\n";
            }
            else
            {
                continue;
                cout << abs(t1.x - t2.x) / 2 % 2 << ' ';
                cout << abs(t1.y - t2.y) / 2 % 2 << ' ';
                cout << abs(t2.x - t.x) / 2 % 2 << ' ';
                cout << abs(t2.y - t.y) / 2 % 2 << ' ';
                cout << "\n";
            }
        }
    }
}

int n;
ban a[N];

int q[2][2];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;

    for (int i = 1; i <= n; ++i)
    {
        a[i].x /= 2;
        a[i].y /= 2;
    }

    for (int i = 1; i <= n; ++i)
        q[a[i].x % 2][a[i].y % 2]++;

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            q[a[i].x % 2][a[i].y % 2]--;
            q[a[j].x % 2][a[j].y % 2]--;

            int zx = abs(a[i].x - a[j].x) % 2;
            int zy = abs(a[i].y - a[j].y) % 2;

            if (zx == 0 && zy == 0)
                ans += (n - 2);
            else if (zx == 1 && zy == 1)
            {
                ans += q[a[j].x % 2][a[j].y % 2];
                ans += q[1 - a[j].x % 2][1 - a[j].y % 2];
            }
            else
            {
                ans += q[a[j].x % 2][a[j].y % 2];
                if (zy == 1)
                {
                    ans += q[a[j].x % 2][1 - a[j].y % 2];
                }
                else
                {
                    ans += q[1 - a[j].x % 2][a[j].y % 2];
                }
            }

            q[a[i].x % 2][a[i].y % 2]++;
            q[a[j].x % 2][a[j].y % 2]++;
        }
    }

    assert(ans % 3 == 0);
    ans /= 3;
    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    //por();
    //return 0;

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}