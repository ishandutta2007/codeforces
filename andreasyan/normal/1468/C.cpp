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
const int N = 500005;

int z;
set<pair<int, int> > s;
set<int> s0;
int u[N];

void solv()
{
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x;
            scanf("%d", &x);

            ++z;
            u[z] = x;

            s0.insert(z);
            s.insert(m_p(-x, z));
        }
        else if (ty == 2)
        {
            int i = *s0.begin();

            printf("%d ", i);

            s0.erase(i);
            s.erase(m_p(-u[i], i));
        }
        else
        {
            int i = s.begin()->se;

            printf("%d ", i);

            s0.erase(i);
            s.erase(m_p(-u[i], i));
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
    solv();
    return 0;
}