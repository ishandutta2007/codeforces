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

int ast(int x, int n, int M)
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

int phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            ans -= (ans / i);
        }
    }
    if (n > 1)
        ans -= (ans / n);
    return ans;
}

int n, M;
int a[N];

vector<int> v;

int rec(int l, int r, int i)
{
    if (v[i] == 1)
        return 0;
    if (l == r)
        return (a[l] % v[i]);

    int q = 0;
    for (int j = l + 1; j <= r; ++j)
    {
        if (a[j] == 1)
            break;
        ++q;
        if (q >= 3)
            return ast(a[l], rec(l + 1, r, i + 1) + v[i + 1], v[i]);
    }

    if (q == 0)
        return (a[l] % v[i]);
    if (q == 1)
        return ast(a[l], a[l + 1], v[i]);

    int x = 1;
    for (int j = 0; j < a[l + 2]; ++j)
    {
        if (x * 1LL * a[l + 1] > 32)
            return ast(a[l], ast(a[l + 1], a[l + 2], v[i + 1]) + v[i + 1], v[i]);
        x *= a[l + 1];
    }
    return ast(a[l], x, v[i]);
}

void solv()
{
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    v.push_back(M);
    while (v.back() != 1)
        v.push_back(phi(v.back()));

    int qq;
    cin >> qq;
    while (qq--)
    {
        int l, r;
        cin >> l >> r;
        cout << rec(l, r, 0) << "\n";
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