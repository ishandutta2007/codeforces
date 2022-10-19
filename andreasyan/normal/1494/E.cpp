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

int n, qq;

int ans1, ans2;
map<pair<int, int>, char> mp;
//int m[N][26], h[N][26];
set<pair<int, int> > s;

void solv()
{
    scanf("%d%d", &n, &qq);
    while (qq--)
    {
        char ty;
        scanf(" %c", &ty);
        if (ty == '+')
        {
            int x, y;
            char z;
            scanf("%d%d %c", &x, &y, &z);

            mp[m_p(x, y)] = z;
            if (z == mp[m_p(y, x)])
                ++ans1;

            s.insert(m_p(x, y));
            if (s.find(m_p(y, x)) != s.end())
                ++ans2;

            /*int maxh = 0, maxm = 0;
            for (int i = 0; i < 26; ++i)
            {
                maxh = max(maxh, h[x][i]);
                maxm = max(maxm, m[x][i]);
            }
            if (maxh >= 2 && maxm >= 2)
                --ans2;
            maxh = 0, maxm = 0;
            for (int i = 0; i < 26; ++i)
            {
                maxh = max(maxh, h[y][i]);
                maxm = max(maxm, m[y][i]);
            }
            if (maxh >= 2 && maxm >= 2)
                --ans2;

            h[x][z - 'a']++;
            m[y][z - 'a']++;

            maxh = 0, maxm = 0;
            for (int i = 0; i < 26; ++i)
            {
                maxh = max(maxh, h[x][i]);
                maxm = max(maxm, m[x][i]);
            }
            if (maxh >= 2 && maxm >= 2)
                ++ans2;
            maxh = 0, maxm = 0;
            for (int i = 0; i < 26; ++i)
            {
                maxh = max(maxh, h[y][i]);
                maxm = max(maxm, m[y][i]);
            }
            if (maxh >= 2 && maxm >= 2)
                ++ans2;*/
        }
        else if (ty == '-')
        {
            int x, y;
            char z;
            scanf("%d%d", &x, &y);
            z = mp[m_p(x, y)];

            if (z == mp[m_p(y, x)])
                --ans1;
            mp[m_p(x, y)] = 0;

            if (s.find(m_p(y, x)) != s.end())
                --ans2;
            s.erase(m_p(x, y));

            /*int maxh = 0, maxm = 0;
            for (int i = 0; i < 26; ++i)
            {
                maxh = max(maxh, h[x][i]);
                maxm = max(maxm, m[x][i]);
            }
            if (maxh >= 2 && maxm >= 2)
                --ans2;
            maxh = 0, maxm = 0;
            for (int i = 0; i < 26; ++i)
            {
                maxh = max(maxh, h[y][i]);
                maxm = max(maxm, m[y][i]);
            }
            if (maxh >= 2 && maxm >= 2)
                --ans2;

            h[x][z - 'a']--;
            m[y][z - 'a']--;

            maxh = 0, maxm = 0;
            for (int i = 0; i < 26; ++i)
            {
                maxh = max(maxh, h[x][i]);
                maxm = max(maxm, m[x][i]);
            }
            if (maxh >= 2 && maxm >= 2)
                ++ans2;
            maxh = 0, maxm = 0;
            for (int i = 0; i < 26; ++i)
            {
                maxh = max(maxh, h[y][i]);
                maxm = max(maxm, m[y][i]);
            }
            if (maxh >= 2 && maxm >= 2)
                ++ans2;*/
        }
        else
        {
            int k;
            scanf("%d", &k);

            if (ans1)
            {
                printf("YES\n");
                continue;
            }
            if (k % 2 == 1)
            {
                if (ans2)
                {
                    printf("YES\n");
                    continue;
                }
            }
            printf("NO\n");
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}