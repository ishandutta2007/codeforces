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

int a, b;
bool stg(int qa, int qb, int x)
{
    int ab = (qa - a + x);
    if (ab % 2 != 0)
        return false;
    ab /= 2;

    int bb = b - ab;
    int ba = x - ab;
    int aa = a - ba;

    return (ab >= 0 && bb >= 0 && ba >= 0 && aa >= 0);
}

void solv()
{
    cin >> a >> b;

    vector<int> ans;
    for (int x = 0; x <= a + b; ++x)
    {
        if (stg((a + b) / 2, (a + b) / 2 + (a + b) % 2, x))
        {
            ans.push_back(x);
        }
        else if (stg((a + b) / 2 + (a + b) % 2, (a + b) / 2, x))
        {
            ans.push_back(x);
        }
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
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}