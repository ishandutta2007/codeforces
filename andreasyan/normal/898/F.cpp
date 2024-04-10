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
const int N = 1000006, M1 = 1000000007;

int n;
char a[N];

ll ast[N], p[N];
ll ast1[N], p1[N];
void pre()
{
    ast[0] = 1;
    for (int i = 1; i <= n; ++i)
        ast[i] = ast[i - 1] * 10;
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] * 10 + (a[i] - '0');
    ast1[0] = 1;
    for (int i = 1; i <= n; ++i)
        ast1[i] = (ast1[i - 1] * 10) % M1;
    for (int i = 1; i <= n; ++i)
        p1[i] = (p1[i - 1] * 10 + (a[i] - '0')) % M1;
}

bool stg0(int al, int ar, int bl, int br, int cl, int cr)
{
    if (!(al <= ar && bl <= br && cl <= cr))
        return false;
    if (!(1 <= al && ar <= n && 1 <= bl && br <= n && 1 <= cl && cr <= n))
        return false;
    if (a[al] == '0' && al != ar)
        return false;
    if (a[bl] == '0' && bl != br)
        return false;
    if (a[cl] == '0' && cl != cr)
        return false;
    ll ah = p[ar] - p[al - 1] * ast[ar - al + 1];
    ll bh = p[br] - p[bl - 1] * ast[br - bl + 1];
    ll ch = p[cr] - p[cl - 1] * ast[cr - cl + 1];
    ll ah1 = (p1[ar] - p1[al - 1] * ast1[ar - al + 1] % M1 + M1) % M1;
    ll bh1 = (p1[br] - p1[bl - 1] * ast1[br - bl + 1] % M1 + M1) % M1;
    ll ch1 = (p1[cr] - p1[cl - 1] * ast1[cr - cl + 1] % M1 + M1) % M1;
    return (ah + bh == ch && (ah1 + bh1) % M1 == ch1);
}

bool stg(int al, int ar, int bl, int br, int cl, int cr)
{
    vector<int> av, bv, cv;
    for (int i = al; i <= ar; ++i)
        av.push_back(a[i] - '0');
    for (int i = bl; i <= br; ++i)
        bv.push_back(a[i] - '0');
    for (int i = cl; i <= cr; ++i)
        cv.push_back(a[i] - '0');
    vector<int> cc;
    reverse(all(av));
    reverse(all(bv));
    while (sz(av) < sz(bv))
        av.push_back(0);
    while (sz(bv) < sz(av))
        bv.push_back(0);
    int m = 0;
    for (int i = 0; i < av.size(); ++i)
    {
        cc.push_back((av[i] + bv[i] + m) % 10);
        m = (av[i] + bv[i] + m) / 10;
    }
    cc.push_back(m);
    while (!cc.empty() && !cc.back())
        cc.pop_back();
    reverse(all(cv));
    while (!cv.empty() && !cv.back())
        cv.pop_back();
    return cc == cv;
}

void print(int al, int ar, int bl, int br, int cl, int cr)
{
    for (int i = al; i <= ar; ++i)
        printf("%c", a[i]);
    printf("+");
    for (int i = bl; i <= br; ++i)
        printf("%c", a[i]);
    printf("=");
    for (int i = cl; i <= cr; ++i)
        printf("%c", a[i]);
    printf("\n");
}

void solv()
{
    scanf(" %s", (a + 1));
    for (n = 1; a[n]; ++n){}
    --n;
    pre();
    for (int d = 1; d <= n; ++d)
    {
        if (stg0(1, n - d - d, n - d - d + 1, n - d, n - d + 1, n))
        {
            if (stg(1, n - d - d, n - d - d + 1, n - d, n - d + 1, n))
            {
                print(1, n - d - d, n - d - d + 1, n - d, n - d + 1, n);
                return;
            }
        }
        if (stg0(1, n - d - d + 1, n - d - d + 2, n - d, n - d + 1, n))
        {
            if (stg(1, n - d - d + 1, n - d - d + 2, n - d, n - d + 1, n))
            {
                print(1, n - d - d + 1, n - d - d + 2, n - d, n - d + 1, n);
                return;
            }
        }
        if (stg0(1, d, d + 1, n - d, n - d + 1, n))
        {
            if (stg(1, d, d + 1, n - d, n - d + 1, n))
            {
                print(1, d, d + 1, n - d, n - d + 1, n);
                return;
            }
        }
        if (stg0(1, d - 1, d, n - d, n - d + 1, n))
        {
            if (stg(1, d - 1, d, n - d, n - d + 1, n))
            {
                print(1, d - 1, d, n - d, n - d + 1, n);
                return;
            }
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}