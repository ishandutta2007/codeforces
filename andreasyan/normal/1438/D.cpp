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
int a[N];

struct ban
{
    int x, y, z;
    ban(){}
    ban(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

vector<ban> ans;
void ubd(int i, int j, int k)
{
    ans.push_back(ban(i, j, k));
    int u = (a[i] ^ a[j] ^ a[k]);
    a[i] = a[j] = a[k] = u;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i += 2)
    {
        if (i + 2 <= n)
        {
            ubd(i, i + 1, i + 2);
        }
        else
        {
            if (i == n)
            {
                for (int j = 1; j != i; j += 2)
                    ubd(j, j + 1, n);
            }
            else
            {
                if (a[i] == a[i + 1])
                {
                    for (int j = 1; j != i; j += 2)
                        ubd(j, j + 1, n);
                }
                else
                {
                    printf("NO\n");
                    return;
                }
            }
        }
    }
    printf("YES\n");
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
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