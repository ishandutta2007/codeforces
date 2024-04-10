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
const int N = 1000006, M = 1000000007;

int n;
int q[N];

void por()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> q[i];

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < q[i]; ++j)
            v.push_back(i);
    }

    int ans = 0;
    do
    {
        int yans = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            for (int j = i + 1; j < sz(v); ++j)
            {
                if (v[i] == v[j])
                    yans += j - i;
            }
        }
        ans = max(ans, yans);
    } while (next_permutation(all(v)));

    do
    {
        int yans = 0;
        for (int i = 0; i < sz(v); ++i)
        {
            for (int j = i + 1; j < sz(v); ++j)
            {
                if (v[i] == v[j])
                    yans += j - i;
            }
        }
        if (yans == ans)
        {
            cout << ans << "\n";
            for (int i = 0; i < sz(v); ++i)
                cout << v[i];
            cout << "\n";
        }
    } while (next_permutation(all(v)));
}

int f[N];
int qq[N];

void solv()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> q[i];

    for (int i = 1; i <= n; ++i)
        qq[q[i]]++;
    ll e = 0;
    for (int i = 1; i <= n; ++i)
        e += q[i];

    int ans = 0, ansq = 1;
    for (int i = N - 1; i >= 1; --i)
    {
        if (!qq[i])
            continue;
        if (i == 1)
        {
            ansq = (ansq * 1LL * f[qq[i]]) % M;
            break;
        }
        ansq = (ansq * 1LL * f[qq[i]]) % M;
        ansq = (ansq * 1LL * f[qq[i]]) % M;

        ll s1 = ((e - 1) + (e - (qq[i] - 1) * 2 - 1));
        ll s2 = qq[i];
        if (s1 % 2 == 0)
            s1 /= 2;
        else if (s2 % 2 == 0)
            s2 /= 2;
        else
            assert(false);
        s1 %= M;
        s2 %= M;
        s1 = (s1 * s2) % M;
        ans = (ans + s1 * (i - 1)) % M;
        e -= 2 * qq[i];

        qq[i - 2] += qq[i];
    }

    cout << ans << ' ' << ansq << "\n";
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
        //por();
        solv();
    }
    return 0;
}