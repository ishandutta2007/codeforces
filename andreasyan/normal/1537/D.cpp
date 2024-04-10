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
const int N = 200005;

vector<int> v[N];
bool dp[N];

void por()
{
    for (int i = 2; i < N; ++i)
    {
        for (int j = i + i; j < N; j += i)
            v[j].push_back(i);
    }
    for (int i = 3; i < N; ++i)
    {
        for (int k = 0; k < sz(v[i]); ++k)
        {
            int j = v[i][k];
            if (i % j == 0)
            {
                if (!dp[i - j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    for (int i = 1; i < N; ++i)
    {
        if (i % 2 == 1)
            assert(!dp[i]);
        else
        {
            if (!dp[i])
                cout << i << ' ';
        }
    }
}

void solv()
{
    int n;
    cin >> n;

    if (n % 2 == 1)
        cout << "Bob\n";
    else
    {
        int q = 0;
        while (n % 2 == 0)
        {
            n /= 2;
            ++q;
        }
        if (n > 1)
            cout << "Alice\n";
        else
        {
            if (q % 2 == 1)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}