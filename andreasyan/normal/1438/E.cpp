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
int a[N];
ll p[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    set<pair<int, int> > s;
    for (int l = 1; l <= n; ++l)
    {
        int r = l + 1;
        while (r < n)
        {
            ++r;
            if (p[r - 1] - p[l] == (a[l] ^ a[r]))
                s.insert(m_p(l, r));
            if (p[r - 1] - p[l] > a[l] * 2)
                break;
        }
    }
    for (int r = n; r >= 1; --r)
    {
        int l = r - 1;
        while (l > 1)
        {
            --l;
            if (p[r - 1] - p[l] == (a[l] ^ a[r]))
                s.insert(m_p(l, r));
            if (p[r - 1] - p[l] > a[r] * 2)
                break;
        }
    }
    printf("%d\n", sz(s));
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