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

void solv()
{
    int n;
    cin >> n;
    set<int> s;
    while (n--)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    if (sz(s) <= 2)
    {
        cout << "YES\n";
    }
    else if (sz(s) == 3)
    {
        auto it = s.begin();
        int x = *it;
        ++it;
        int y = *it;
        ++it;
        int z = *it;
        if (x + z == 2 * y)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(15);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}