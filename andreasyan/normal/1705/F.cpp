#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2100);
const int N = 1003;

ll C(int n, int k)
{
    ll ans = 1;
    for (int i = n; i >= n - k + 1; --i)
        ans *= i;
    for (int i = 1; i <= k; ++i)
        ans /= i;
    return ans;
}

long double dp[N][N];
void por()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i + j < 4)
                dp[i][j] = i + j;
            else
            {
                long double q = C(i + j, 4);
                for (int ii = 0; ii <= 4; ++ii)
                {
                    int jj = 4 - ii;
                    ll yq = C(i, ii) * C(j, jj);
                    if (yq == 0)
                        continue;

                    if (min(ii, jj) == 0)
                        dp[i][j] += (yq / q) * (dp[i - ii][j - jj] + 1);
                    else if (min(ii, jj) == 1)
                    {
                        if (ii == 1)
                            dp[i][j] += (yq / q) * (dp[i - 1][j - 2] * 0.5 + dp[i][j - 3] * 0.5 + 2);
                        else
                            dp[i][j] += (yq / q) * (dp[i - 2][j - 1] * 0.5 + dp[i - 3][j] * 0.5 + 2);
                    }
                    else
                        dp[i][j] += (yq / q) * (0.5 * (dp[i - 2][j - 2] + 2) + 0.5 * (dp[i - 1][j - 1] * 0.5 + dp[i - 2][j] * 0.25 + dp[i][j - 2] * 0.25 + 2));
                }
            }
        }
    }

    long double maxu = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i + j == 1000)
                maxu = max(maxu, dp[i][j]);
        }
    }
    cout << maxu << "\n";
}

int n;
char aa[N];
int qry(const vector<int>& v)
{
    assert(sz(v) == n);
    for (int i = 0; i < n; ++i)
    {
        if (v[i] == 0)
            cout << 'F';
        else
            cout << 'T';
    }
    cout << endl;
    int ans = 0;
    /*for (int i = 0; i < n; ++i)
    {
        if (v[i] == 0 && aa[i] == 'F')
            ++ans;
        if (v[i] == 1 && aa[i] == 'T')
            ++ans;
    }*/
    cin >> ans;
    if (ans == n)
        exit(0);
    return ans;
}

void solv()
{
    cin >> n;
    //cin >> aa;

    vector<int> v;
    v.assign(n, 0);

    int ans0 = qry(v);

    vector<int> ans;
    ans.assign(n, 0);
    vector<int> x;
    for (int i = 0; i < n; ++i)
        x.push_back(i);
    while (1)
    {
        if (sz(x) < 4)
        {
            for (int i = 0; i < sz(x); ++i)
            {
                v.assign(n, 0);
                v[x[i]] = 1;
                int t = qry(v) - ans0;
                if (t > 0)
                    ans[x[i]] = 1;
                else
                    ans[x[i]] = 0;
            }
            x.clear();
            break;
        }
        for (int i = sz(x) - 1; i >= 0; --i)
        {
            swap(x[i], x[rnd() % (i + 1)]);
        }

        v.assign(n, 0);
        for (int i = 0; i < 4; ++i)
            v[x[i]] = 1;
        int t = qry(v) - ans0;
        int q0 = (4 - t) / 2;

        if (q0 == 0)
        {
            for (int i = 0; i < 4; ++i)
                ans[x[i]] = 1;
            reverse(all(x));
            for (int i = 0; i < 4; ++i)
                x.pop_back();
        }
        else if (q0 == 4)
        {
            for (int i = 0; i < 4; ++i)
                ans[x[i]] = 0;
            reverse(all(x));
            for (int i = 0; i < 4; ++i)
                x.pop_back();
        }
        else if (q0 == 1)
        {
            v.assign(n, 0);
            v[x[0]] = v[x[1]] = 1;
            int t = qry(v) - ans0;
            int q00 = (2 - t) / 2;

            if (q00 == 0)
            {
                ans[x[0]] = ans[x[1]] = 1;
                ans[x[2]] = -(x[3] + 1);
            }
            else
            {
                assert(q00 == 1);
                swap(x[0], x[2]);
                swap(x[1], x[3]);
                ans[x[0]] = ans[x[1]] = 1;
                ans[x[2]] = -(x[3] + 1);
            }
            reverse(all(x));
            for (int i = 0; i < 3; ++i)
                x.pop_back();
        }
        else if (q0 == 3)
        {
            v.assign(n, 0);
            v[x[0]] = v[x[1]] = 1;
            int t = qry(v) - ans0;
            int q00 = (2 - t) / 2;

            if (q00 == 2)
            {
                ans[x[0]] = ans[x[1]] = 0;
                ans[x[2]] = -(x[3] + 1);
            }
            else
            {
                assert(q00 == 1);
                swap(x[0], x[2]);
                swap(x[1], x[3]);
                ans[x[0]] = ans[x[1]] = 0;
                ans[x[2]] = -(x[3] + 1);
            }
            reverse(all(x));
            for (int i = 0; i < 3; ++i)
                x.pop_back();
        }
        else
        {
            assert(q0 == 2);
            v.assign(n, 0);
            v[x[0]] = v[x[1]] = 1;
            int t = qry(v) - ans0;
            int q00 = (2 - t) / 2;

            if (q00 == 0)
            {
                ans[x[0]] = ans[x[1]] = 1;
                ans[x[2]] = ans[x[3]] = 0;
                reverse(all(x));
                for (int i = 0; i < 4; ++i)
                    x.pop_back();
            }
            else if (q00 == 2)
            {
                ans[x[0]] = ans[x[1]] = 0;
                ans[x[2]] = ans[x[3]] = 1;
                reverse(all(x));
                for (int i = 0; i < 4; ++i)
                    x.pop_back();
            }
            else
            {
                assert(q00 == 1);
                ans[x[0]] = -(x[1] + 1);
                ans[x[2]] = -(x[3] + 1);
                swap(x[2], x[1]);
                reverse(all(x));
                for (int i = 0; i < 2; ++i)
                    x.pop_back();
            }
        }
    }

    while (1)
    {
        bool z = false;
        for (int i = 0; i < n; ++i)
        {
            if (ans[i] < 0)
            {
                z = true;
                if (ans[-ans[i] - 1] >= 0)
                    ans[i] = 1 - ans[-ans[i] - 1];
            }
        }
        if (!z)
            break;
    }

    qry(ans);
    assert(false);
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