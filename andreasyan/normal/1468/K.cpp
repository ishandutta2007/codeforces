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
const int N = 5003;

int n;
char a[N];

void solv()
{
    scanf(" %s", a);
    n = strlen(a);

    pair<int, int> u = m_p(0, 0);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'L')
            u.fi--;
        else if (a[i] == 'R')
            u.fi++;
        else if (a[i] == 'D')
            u.se--;
        else
            u.se++;
        if (u != m_p(0, 0));
        {
            pair<int, int> uu = m_p(0, 0);
            for (int j = 0; j < n; ++j)
            {
                pair<int, int> yu = uu;
                if (a[j] == 'L')
                    uu.fi--;
                else if (a[j] == 'R')
                    uu.fi++;
                else if (a[j] == 'D')
                    uu.se--;
                else
                    uu.se++;
                if (uu == u)
                    uu = yu;
            }
            if (uu == m_p(0, 0))
            {
                printf("%d %d\n", u.fi, u.se);
                return;
            }
        }
    }
    printf("0 0\n");
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
    {
        solv();
    }
    return 0;
}