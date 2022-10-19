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
const int N = 5003, M = 1000006;

int n, k;
int a[N];

//vector<pair<int, int> > v[M];
int q[M];

bool c[N];
bool cc[M];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            //if (v[abs(a[i] - a[j])].size() <= (k * (k + 1)) / 2)
            //{
            //    v[abs(a[i] - a[j])].push_back(m_p(i, j));
                ++q[abs(a[i] - a[j])];
            //}
        }
    }
    for (int i = 1; i < M; ++i)
    {
        int qq = 0;
        for (int j = i; j < M; j += i)
            qq += q[j];
        if (qq > (k * (k + 1)) / 2)
            continue;
        int kk = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (cc[a[j] % i])
            {
                ++kk;
                if (kk > k)
                    break;
            }
            else
                cc[a[j] % i] = true;
        }
        if (kk <= k)
        {
            printf("%d\n", i);
            return;
        }
        for (int j = 1; j <= n; ++j)
            cc[a[j] % i] = false;
        /*vector<int> s;
        for (int j = i; j < M; j += i)
        {
            for (int k = 0; k < v[j].size(); ++k)
            {
                if (!c[v[j][k].fi])
                {
                    c[v[j][k].fi] = true;
                    s.push_back(v[j][k].fi);
                }
                if (!c[v[j][k].se])
                {
                    c[v[j][k].se] = true;
                    s.push_back(v[j][k].se);
                }
            }
        }
        int kk = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            if (cc[(a[s[j]] % i)])
                ++kk;
            else
                cc[(a[s[j]] % i)] = true;
        }
        if (kk <= k)
        {
            printf("%d\n", i);
            return;
        }
        for (int j = 0; j < s.size(); ++j)
        {
            c[s[j]] = false;
            cc[(a[s[j]] % i)] = false;
        }*/
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}