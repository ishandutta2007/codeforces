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

int p[N];
int s[N];

void solv()
{
    scanf("%d", &n);

    for (int i = 0; i <= n + 1; ++i)
    {
        p[i] = s[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
        p[i] = max(a[i], p[i - 1]);
    for (int i = n; i >= 1; --i)
        s[i] = max(a[i], s[i + 1]);

    stack<pair<int, int> > st;
    map<int, pair<int, int> > mp;
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = i - 2;
        int jl = n + 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[m] >= s[i])
            {
                jl = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

         l = 1;
         r = i - 2;
        int jr = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[m] <= s[i])
            {
                jr = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }

        pair<int, int> u = m_p(n + 1, 0);
        if (mp.find(s[i]) != mp.end())
            u = mp[s[i]];

         l = max(jl, u.fi - 1);
         r = min(jr, u.se - 1);
        if (l <= r)
        {
            printf("YES\n");
            printf("%d %d %d\n", r, n - r - (n - i + 1), n - i + 1);
            return;
        }

        int su = i;
        while (!st.empty() && a[i] <= a[st.top().se])
        {
            mp.erase(a[st.top().se]);
            su = st.top().fi;
            st.pop();
        }
        st.push(m_p(su, i));
        mp[a[i]] = st.top();
    }
    printf("NO\n");
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