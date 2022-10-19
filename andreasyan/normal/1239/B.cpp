#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2100);
const int N = 300005;

int n;
char a[N];
char b[N];

int p[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));

    int q = 0;
    int minu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '(')
            ++q;
        else
            --q;
        minu = min(minu, q);
    }

    if (q != 0)
    {
        printf("0\n");
        printf("1 1\n");
        return;
    }

    int s;
    for (int i = 1; i <= n; ++i)
    {
        if (q == minu)
        {
            s = i;
            break;
        }
        if (a[i] == '(')
            ++q;
        else
            --q;
    }

    int m = 0;
    for (int i = s; i <= n; ++i)
        b[++m] = a[i];
    for (int i = 1; i < s; ++i)
        b[++m] = a[i];
    for (int i = 1; i <= n; ++i)
        a[i] = b[i];

    int sans = 0;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] == '(')
            ++p[i];
        else
            --p[i];
        if (p[i] == 0)
            ++sans;
    }

    int ans = sans;
    int ansl = 1, ansr = 1;

    vector<int> v[3];
    for (int i = 0; i <= n; ++i)
    {
        if (p[i] < 3)
            v[p[i]].push_back(i);
    }

    for (int i = 0; i < sz(v[0]) - 1; ++i)
    {
        int yansl = v[0][i] + 1, yansr = v[0][i + 1];
        int yans = upper_bound(all(v[1]), yansr) - lower_bound(all(v[1]), yansl);
        if (yans > ans)
        {
            ans = yans;
            ansl = yansl;
            ansr = yansr;
        }
    }

    for (int i = 0; i < sz(v[1]) - 1; ++i)
    {
        int yansl = v[1][i] + 1, yansr = v[1][i + 1];
        int u = upper_bound(all(v[0]), yansr) - lower_bound(all(v[0]), yansl);
        if (u)
            continue;
        int yans = sans + upper_bound(all(v[2]), yansr) - lower_bound(all(v[2]), yansl);
        if (yans > ans)
        {
            ans = yans;
            ansl = yansl;
            ansr = yansr;
        }
    }

    ansl = s + ansl - 1;
    if (ansl > n)
        ansl -= n;

    ansr = s + ansr - 1;
    if (ansr > n)
        ansr -= n;

    printf("%d\n", ans);
    printf("%d %d\n", ansl, ansr);
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