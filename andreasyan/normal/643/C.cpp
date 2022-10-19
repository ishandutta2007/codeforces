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
const int N = 200005, K = 55;
const ll INF = 1000000009000000009;

int n, k;
double a[N];

double p[N];

double p1[N];

double p2[N];

double dp[N];

double ndp[N];

struct line
{
    double b, k;
    line(){}
    line(double b, double k)
    {
        this->b = b;
        this->k = k;
    }
    double yat(double x)
    {
        return b + k * x;
    }
};

double hat(const line& t1, const line& t2)
{
    return (t2.b - t1.b) / (t1.k - t2.k);
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
        p1[i] = p1[i - 1] + p[i] / a[i];
    for (int i = 1; i <= n; ++i)
        p2[i] = p2[i - 1] - 1 / a[i];
    for (int i = 1; i <= n; ++i)
        dp[i] = p1[i];
    for (int ii = 2; ii <= k; ++ii)
    {
        deque<line> t;
        deque<double> v;
        int j = 0;
        for (int i = 0; i <= n; ++i)
        {
            if (i >= ii)
            {
                while (j > 0 && v[j - 1] > p2[i])
                    --j;
                while (v[j] <= p2[i])
                    ++j;
                ndp[i] = t[j].yat(p2[i]) + p1[i];
            }
            else
                ndp[i] = INF;
            line nt = line(dp[i] - p1[i] + p[i] * (-p2[i]), p[i]);
            while (t.size() >= 2 && hat(nt, t.front()) >= v.front())
            {
                t.pop_front();
                v.pop_front();
                j = max(j - 1, 0);
            }
            if (!t.empty())
                v.push_front(hat(nt, t.front()));
            t.push_front(nt);
        }
        for (int i = 0; i <= n; ++i)
            dp[i] = ndp[i];
    }
    printf("%.10f\n", dp[n]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}