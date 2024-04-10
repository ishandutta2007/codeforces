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

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    set<int> s;
    set<pair<int, int> > s1, s2, s3;
    for (int i = 1; i <= n; ++i)
        s.insert(i);
    vector<pair<int, int> > ans;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == 1)
        {
            int x = *(--s.end());
            s.erase(x);
            ans.push_back(m_p(x, i));
            s1.insert(m_p(x, i));
        }
        else if (a[i] == 2)
        {
            if (s1.empty())
            {
                printf("-1\n");
                return;
            }
            pair<int, int> u = *s1.begin();
            s1.erase(u);
            ans.push_back(m_p(u.fi, i));
            s2.insert(m_p(u.fi, i));
        }
        else if (a[i] == 3)
        {
            if (!s2.empty())
            {
                int x = (*(--s.end()));
                s.erase(x);
                pair<int, int> u = *s2.begin();
                s2.erase(u);
                ans.push_back(m_p(x, i));
                ans.push_back(m_p(x, u.se));
                s3.insert(m_p(x, i));
            }
            else if (!s3.empty())
            {
                int x = (*(--s.end()));
                s.erase(x);
                pair<int, int> u = *s3.begin();
                s3.erase(u);
                ans.push_back(m_p(x, i));
                ans.push_back(m_p(x, u.se));
                s3.insert(m_p(x, i));
            }
            else if (!s1.empty())
            {
                int x = (*(--s.end()));
                s.erase(x);
                pair<int, int> u = *s1.begin();
                s1.erase(u);
                ans.push_back(m_p(x, i));
                ans.push_back(m_p(x, u.se));
                s3.insert(m_p(x, i));
            }
            else
            {
                printf("-1\n");
                return;
            }
        }
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d %d\n", ans[i].fi, ans[i].se);
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