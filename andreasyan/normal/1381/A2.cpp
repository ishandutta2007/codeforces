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
const int N = 100005;

int n;
char a[N], b[N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s %s", (a + 1), (b + 1));

    vector<int> ans;

    int i = n;
    int l = 1, r = n;
    bool z = false;
    while (i)
    {
        if (!z)
        {
            if (a[r] == b[i])
            {
                --r;
            }
            else if (a[l] != b[i])
            {
                ans.push_back((r - l + 1));
                ++l;
                z ^= true;
            }
            else
            {
                ans.push_back(1);
                ans.push_back((r - l + 1));
                ++l;
                z ^= true;
            }
        }
        else
        {
            if (a[l] != b[i])
            {
                ++l;
            }
            else if (a[r] == b[i])
            {
                ans.push_back((r - l + 1));
                --r;
                z ^= true;
            }
            else
            {
                ans.push_back(1);
                ans.push_back((r - l + 1));
                --r;
                z ^= true;
            }
        }
        --i;
    }
    printf("%d ", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d ", ans[i]);
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