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
const int N = 102;

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    int ans = a[n];
    for (int q1 = 0; q1 <= 4; ++q1)
    {
        for (int q2 = 0; q2 <= 4; ++q2)
        {
            vector<int> v;
            for (int i = 0; i <= q1; ++i)
            {
                for (int j = 0; j <= q2; ++j)
                {
                    v.push_back(i + j * 2);
                }
            }

            if (q1 == 0 && q2 == 2)
                cout << "";

            int yans = 0;
            for (int i = 1; i <= n; ++i)
            {
                int yyans = a[n];
                for (int j = 0; j < sz(v); ++j)
                {
                    if (a[i] >= v[j] && (a[i] - v[j]) % 3 == 0)
                    {
                        yyans = min(yyans, (a[i] - v[j]) / 3);
                    }
                }
                yans = max(yans, yyans);
            }
            yans += (q1 + q2);

            ans = min(ans, yans);
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

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}