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
const int N = 2000006;

int n;

int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        a[i] = i;
    }

    vector<pair<int, int> > v;
    for (int k = 2; k <= n; ++k)
    {
        v.clear();
        for (int u = 1; u <= n; u += k)
        {
            int nu;
            if (u + k - 1 <= n)
                nu = u + k - 1;
            else
                nu = n;
            int i = a[u + (k - 2)];
            v.push_back(m_p(nu + (k - 1), i));
        }
        for (int i = 0; i < sz(v); ++i)
            a[v[i].fi] = v[i].se;
    }

    for (int u = 1; u <= n; ++u)
    {
        int i = a[u + (n - 1)];
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}