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
const int N = 2003;
const ll INF = 1000000009003003;
#define double long double

int n;
int xl[N], xr[N], y[N];

ll f(int x1, int y1_, int x2, int y2, int x3, int y3)
{
    return (x1 - x3) * 1LL * (y1_ - y2) - (y1_ - y3) * 1LL * (x1 - x2);
}

double getx(double x, double y, double a, double b)
{
    double k = -y / b;
    return x + k * a;
}

double stg(int a, int b)
{
    double minu = INF;
    double maxu = -INF;
    for (int i = 1; i <= n; ++i)
    {
        double k = -y[i] / (double)b;
        minu = min(minu, xl[i] + k * a);
        maxu = max(maxu, xr[i] + k * a);
    }

    return maxu - minu;
}

struct ban
{
    int a, b;
    int z;
    ban(){}
    ban(int a, int b, int z)
    {
        this->a = a;
        this->b = b;
        this->z = z;
    }
};

bool operator<(const ban& a, const ban& b)
{
    if (f(0, 0, a.a, a.b, b.a, b.b) < 0)
        return true;
    if (f(0, 0, a.a, a.b, b.a, b.b) > 0)
        return false;
    return a.z > b.z;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> xl[i] >> xr[i] >> y[i];

    /*n = 2000;
    for (int i = 1; i <= n; ++i)
    {
        xl[i] = -1000000;
        xr[i] = 1000000;
        y[i] = i;
    }*/

    double ans = INF;
    {
        vector<ban> v;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (y[i] > y[j])
                {
                    {
                        int b = (y[j] - y[i]);
                        int a = (xl[j] - xr[i]);
                        v.push_back(ban(a, b, -1));
                    }
                    {
                        int b = (y[j] - y[i]);
                        int a = (xr[j] - xl[i]);
                        v.push_back(ban(a, b, 1));
                    }
                }
            }
        }
        v.push_back(ban(0, -1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (y[i] > y[j])
                {
                    if (getx(xl[i], y[i], -INF, -1) < getx(xl[j], y[j], -INF, -1))
                    {
                        v.push_back(ban(xl[j] - xl[i], y[j] - y[i], 2 * (i * N + j) + 1));
                    }
                    else
                    {
                        v.push_back(ban(xl[j] - xl[i], y[j] - y[i], 2 * (j * N + i) + 1));
                    }
                    if (getx(xr[i], y[i], -INF, -1) > getx(xr[j], y[j], -INF, -1))
                    {
                        v.push_back(ban(xr[j] - xr[i], y[j] - y[i], 2 * (i * N + j)));
                    }
                    else
                    {
                        v.push_back(ban(xr[j] - xr[i], y[j] - y[i], 2 * (j * N + i)));
                    }
                }
            }
        }

        sort(all(v));

        int mini = 1, maxi = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (getx(xl[i], y[i], -INF, -1) < getx(xl[mini], y[mini], -INF, -1))
                mini = i;
            if (getx(xr[i], y[i], -INF, -1) > getx(xr[maxi], y[maxi], -INF, -1))
                maxi = i;
        }

        int q = n;
        vector<ban> u;
        for (int i = 0; i < v.size(); ++i)
        {
            if (abs(v[i].z) <= 1)
            {
                if (max(q, q + v[i].z) == n)
                {
                    ans = min(ans, getx(xr[maxi], y[maxi], v[i].a, v[i].b) - getx(xl[mini], y[mini], v[i].a, v[i].b));
                }
                q += v[i].z;
            }
            else
            {
                if (v[i].z % 2 == 1)
                {
                    v[i].z /= 2;
                    if (v[i].z / N == mini)
                        mini = v[i].z % N;
                }
                else
                {
                    v[i].z /= 2;
                    if (v[i].z / N == maxi)
                        maxi = v[i].z % N;
                }
            }
        }
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

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}