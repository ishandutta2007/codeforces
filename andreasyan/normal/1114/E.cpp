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
const int N = 1000006, M = 1000000000, Q = 60;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int u[N];

void solv()
{
    scanf("%d", &n);
    int l = 0, r = M;
    int maxu = 0;
    int q = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        ++q;
        printf("> %d\n", m);
        fflush(stdout);
        int z;
        scanf("%d", &z);
        if (z)
        {
            maxu = m + 1;
            l = m + 1;
        }
        else
            r = m - 1;
    }

    for (int i = 1; i <= n; ++i)
        u[i] = i;
    for (int i = n; i >= 1; --i)
        swap(u[i], u[rnd() % i + 1]);
    vector<int> v;
    for (int i = 1; i <= min(n, Q - q); ++i)
    {
        printf("? %d\n", u[i]);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    v.push_back(maxu);

    int d = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            d = gcd(d, abs(v[i] - v[j]));
        }
    }

    printf("! %d %d\n", maxu - (n - 1) * d, d);
    fflush(stdout);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}