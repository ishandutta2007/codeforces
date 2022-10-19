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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    set<int> s;
    set<int> v;
    for (int i = 1; i <= n; ++i)
    {
        s.insert(i);
        if (i > 1)
        {
            if (gcd(a[i], a[i - 1]) == 1)
                v.insert(i);
        }
        else
        {
            if (gcd(a[i], a[n]) == 1)
                v.insert(i);
        }
    }

    vector<int> ans;

    int i = 2;
    while (!v.empty())
    {
        auto it = v.lower_bound(i);
        if (it == v.end())
            it = v.begin();

        int x = *it;
        ans.push_back(x);
        s.erase(x);
        v.erase(x);

        if (s.empty())
            break;
        auto itr = s.lower_bound(x);
        if (itr == s.end())
            itr = s.begin();
        auto itl = itr;
        if (itl == s.begin())
            itl = (--s.end());
        else
            --itl;
        if (v.find(*itr) != v.end())
            v.erase(*itr);
        if (gcd(a[*itl], a[*itr]) == 1)
            v.insert(*itr);

        i = *itr % n + 1;
    }

    cout << sz(ans);
    for (int i = 0; i < sz(ans); ++i)
        cout << ' ' << ans[i];
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
    //scanf("%d", &tt);
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}