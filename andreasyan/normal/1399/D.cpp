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
char a[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", a);
    int yans = 0;
    int minu = 0, maxu = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '0')
            --yans;
        else
            ++yans;
        minu = min(minu, yans);
        maxu = max(maxu, yans);
    }
    printf("%d\n", maxu - minu);
    vector<int> v1;
    vector<int> v2;
    for (int i = 1; i <= maxu; ++i)
        v1.push_back(i);
    for (int i = maxu + 1; i <= maxu - minu; ++i)
        v2.push_back(i);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '0')
        {
            printf("%d ", v2.back());
            v1.push_back(v2.back());
            v2.pop_back();
        }
        else
        {
            printf("%d ", v1.back());
            v2.push_back(v1.back());
            v1.pop_back();
        }
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
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}