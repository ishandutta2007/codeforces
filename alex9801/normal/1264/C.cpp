#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int ipow(int x, int y)
{
    if(y == 0)
        return 1;
    if(y % 2)
        return 1LL * ipow(x, y - 1) * x % mod;
    int t = ipow(x, y / 2);
    return 1LL * t * t % mod;
}
int inv(int x)
{
    assert(x != 0);
    return ipow(x, mod - 2);
}

int arr[200010];
bool chk[200010];

int pre[110];
int rev[110];

int mul[200010];
int mulinv[200010];
int msum[200010];

int calc(int s, int g)
{
    return 1LL * (msum[g] - msum[s - 1] + mod) * mulinv[s - 1] % mod;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = n; i >= 1; i--)
        scanf("%d", &arr[i]);

    int inv100 = inv(100);
    for(int i = 1; i <= 100; i++)
    {
        pre[i] = 1LL * i * inv100 % mod;
        rev[i] = inv(pre[i]);
    }

    mul[0] = 1;
    for(int i = 1; i <= n; i++)
        mul[i] = 1LL * mul[i - 1] * rev[arr[i]] % mod;

    mulinv[0] = 1;
    for(int i = 1; i <= n; i++)
        mulinv[i] = 1LL * mulinv[i - 1] * pre[arr[i]] % mod;

    msum[0] = 0;
    for(int i = 1; i <= n; i++)
        msum[i] = (msum[i - 1] + mul[i]) % mod;

    set<int> s;
    s.insert(1);
    s.insert(n + 1);

    int cur = calc(1, n);
    for(int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        x = n - x + 2;

        if(chk[x])
        {
            chk[x] = 0;

            auto it = s.find(x);
            assert(it != s.end());

            int nxt = *next(it);
            int prv = *prev(it);

            cur = (cur - calc(x, nxt - 1) + mod) % mod;
            cur = (cur - calc(prv, x - 1) + mod) % mod;
            cur = (cur + calc(prv, nxt - 1)) % mod;

            s.erase(it);
        }
        else
        {
            chk[x] = 1;
            auto ret = s.insert(x);
            assert(ret.second);

            auto it = ret.first;

            int nxt = *next(it);
            int prv = *prev(it);

            cur = (cur - calc(prv, nxt - 1) + mod) % mod;
            cur = (cur + calc(prv, x - 1)) % mod;
            cur = (cur + calc(x, nxt - 1)) % mod;
        }

        printf("%d\n", cur);
    }
    return 0;
}