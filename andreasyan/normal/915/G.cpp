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
const int N = 2000006, M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n, k;
vector<int> v[N];

int c[N];
int q[N];

int astt[N];
void pre()
{
    for (int i = 1; i <= k; ++i)
        astt[i] = ast(i, n);
}

int ans[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i)
    {
        for (int j = i; j <= k; j += i)
            v[j].push_back(i);
    }
    for (int i = 2; i <= k; ++i)
    {
        if (c[i])
            continue;
        for (int j = i; j <= k; j += i)
        {
            if (!c[j])
                c[j] = i;
        }
    }
    pre();
    for (int i = 1; i <= k; ++i)
    {
        bool z = true;
        int na = 0;
        int x = i;
        int qq = 0;
        while (x > 1)
        {
            if (c[x] == na)
            {
                z = false;
                break;
            }
            na = c[x];
            x /= c[x];
            ++qq;
        }
        if (!z)
            continue;
        if (qq % 2 == 0)
            q[i] = 1;
        else
            q[i] = -1;
    }
    int yans = 0;
    int ans = 1;
    for (int i = 2; i <= k; ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j];
            if (q[x] == 1)
            {
                ans = (ans - astt[(i - 1) / x] + M) % M;
                ans = (ans + astt[i / x]) % M;
            }
            else if (q[x] == -1)
            {
                ans = (ans + astt[(i - 1) / x]) % M;
                ans = (ans - astt[i / x] + M) % M;
            }
        }
        yans = (yans + (ans ^ i)) % M;
    }
    printf("%d\n", yans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}