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

int l, r, k;

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if ((x % i) == 0)
            return false;
    }
    return true;
}

int q(int x)
{
    int q = 0;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            if (i >= k)
                return -1;
            ++q;
            x /= i;
            if (x % i == 0)
                return -1;
        }
    }
    if ((x > 1))
    {
        if (x >= k)
            return -1;
        ++q;
    }
    return q;
}

int ans;
void rec(const vector<int>& v, int x, int i, int u, int q)
{
    if (i == sz(v))
    {
        if (q % 2 == 0)
            ans += (x / (u * k));
        else
            ans -= (x / (u * k));
        return;
    }
    rec(v, x, i + 1, u, q);
    if (u * 1LL * v[i] * k <= x)
        rec(v, x, i + 1, u * v[i], q + 1);
}

int p(int x)
{
    ans = 0;
    if (k > 20000)
    {
        for (int i = 1; ; ++i)
        {
            if (i * 1LL * k > x)
                break;
            int u = q(i);
            if (u == -1)
                continue;
            if (u % 2 == 0)
                ans += (x / (i * k));
            else
                ans -= (x / (i * k));
        }
        return ans;
    }
    vector<int> v;
    for (int i = 2; i < k; ++i)
    {
        if (prime(i))
        {
            v.push_back(i);
        }
    }
    rec(v, x, 0, 1, 0);
    return ans;
}

int p0(int x)
{
    int ans = 0;
    for (int i = 1; i <= x; ++i)
    {
        if (i % k == 0)
        {
            bool z = true;
            for (int j = 2; j < k; ++j)
            {
                if (i % j == 0)
                {
                    z = false;
                    break;
                }
            }
            if (z)
                ++ans;
        }
    }
    return ans;
}

void solv()
{
    scanf("%d%d%d", &l, &r, &k);
    if (!prime(k))
    {
        printf("0\n");
        return;
    }
    printf("%d\n", p(r) - p(l - 1));
    //printf("%d\n", p0(r) - p0(l - 1));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}