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

ll p;
int k;

void solv()
{
    cin >> p >> k;

    vector<int> ans;
    for (int i = 0; ; ++i)
    {
        if (0 <= p && p < k)
        {
            ans.push_back(p);
            break;
        }
        ll q;
        if (p >= k)
        {
            q = -(p / k);
        }
        else
        {
            q = (-p / k);
            if ((-p) % k != 0)
                ++q;
        }
        ans.push_back(p + q * k);
        p = q;
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i] << ' ';
    cout << "\n";
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