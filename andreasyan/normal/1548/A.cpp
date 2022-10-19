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

int n, m;

int q[N];
int qq;

void solv()
{
    cin >> n >> m;

    qq = n;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);

        q[x]++;
        if (q[x] == 1)
            --qq;
    }

    cin >> m;
    while (m--)
    {
        int ty;
        cin >> ty;

        if (ty == 1)
        {
            int x, y;
            cin >> x >> y;
            if (x > y)
                swap(x, y);

            q[x]++;
            if (q[x] == 1)
                --qq;
        }
        else if (ty == 2)
        {
            int x, y;
            cin >> x >> y;
            if (x > y)
                swap(x, y);

            q[x]--;
            if (q[x] == 0)
                ++qq;
        }
        else
            cout << qq << "\n";
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}