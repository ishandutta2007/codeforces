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
const int N = 502;

int n;
int k[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> k[i];
    vector<pair<int, pair<int, int> > > v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            v.push_back(m_p(abs(k[i] - k[j]), m_p(i, j)));
        }
    }
    sort(all(v));
    reverse(all(v));
    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i].se.fi;
        int y = v[i].se.se;
        if (k[x] < k[y])
            swap(x, y);
        cout << "? " << x << ' ' << y << endl;
        string ans;
        cin >> ans;
        if (ans == "Yes")
        {
            cout << "! " << x << ' ' << y << endl;
            return;
        }
    }
    cout << "! 0 0" << endl;
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
        solv();
    return 0;
}