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

int n;
int q[N];
int qq[N];

multiset<int> s;

bool stg()
{
    if (*(--s.end()) >= 8)
        return true;
    if ((qq[4] + qq[5] + qq[6] + qq[7]) >= 2)
        return true;
    if ((qq[4] + qq[5] + qq[6] + qq[7]) == 1)
    {
        if ((qq[4] + qq[5]))
            return (qq[2] + qq[3]) >= 2;
        else
            return (qq[2] + qq[3]) >= 1;
    }
    return false;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= 100000; ++i)
        s.insert(0);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        s.erase(s.find(q[x]));
        --qq[q[x]];
        ++q[x];
        ++qq[q[x]];
        s.insert(q[x]);
    }
    int qqq;
    scanf("%d", &qqq);
    while (qqq--)
    {
        char ty;
        int x;
        scanf(" %c%d", &ty, &x);
        s.erase(s.find(q[x]));
        --qq[q[x]];
        if (ty == '+')
        {
            ++q[x];
        }
        else
        {
            --q[x];
        }
        ++qq[q[x]];
        s.insert(q[x]);
        if (stg())
            printf("YES\n");
        else
            printf("NO\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}