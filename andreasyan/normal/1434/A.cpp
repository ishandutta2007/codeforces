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
const int N = 100005, INF = 1000000009;

int a[7];
int n;
int b[N];

int minu[N];

void solv()
{
    for (int i = 1; i <= 6; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);

    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 6; ++j)
        {
            v.push_back(m_p(b[i] - a[j], i));
        }
    }
    sort(v.begin(), v.end());

    for (int i = 1; i <= n; ++i)
        minu[i] = INF;
    multiset<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(minu[i]);

    int ans = INF;
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        s.erase(s.find(minu[v[i].se]));
        minu[v[i].se] = v[i].fi;
        s.insert(v[i].fi);
        if (*(--s.end()) == INF)
            continue;
        ans = min(ans, *(--s.end()) - v[i].fi);
    }
    printf("%d\n", ans);
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