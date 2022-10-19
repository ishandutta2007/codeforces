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
const int n = 1000000000;

int qry(int x, int y)
{
    cout << "? " << x << ' ' << y << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solv()
{
    int x1, y1_, x2, y2;

    {
        int d1 = qry(1, 1);
        int d2 = qry(1, n);
        int y = (d1 + 1 - d2 + n) / 2;
        int d = qry(1, y);
        x1 = d + 1;
    }
    {
        int d1 = qry(n, 1);
        int d2 = qry(n, n);
        int y = (d1 + 1 - d2 + n) / 2;
        int d = qry(n, y);
        x2 = n - d;
    }
    {
        int d1 = qry(1, 1);
        int d2 = qry(n, 1);
        int x = (d1 + 1 - d2 + n) / 2;
        int d = qry(x, 1);
        y1_ = d + 1;
    }
    {
        int d1 = qry(1, n);
        int d2 = qry(n, n);
        int x = (d1 + 1 - d2 + n) / 2;
        int d = qry(x, n);
        y2 = n - d;
    }

    cout << "! " << x1 << ' ' << y1_ << ' ' << x2 << ' ' << y2 << endl;
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