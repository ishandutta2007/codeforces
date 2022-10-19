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
const int N = 502;

void por()
{
    int n;
    scanf("%d", &n);
    set<vector<int> > s;
    queue<vector<int> > q;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i);
    }
    s.insert(v);
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (int i = 0; i < n / 2; ++i)
        {
            vector<int> h = v;
            for (int j = 0, k = n - i - 1; j <= i; ++j, ++k)
                swap(h[j], h[k]);
            if (s.find(h) == s.end())
            {
                s.insert(h);
                q.push(h);
            }
        }
    }
    printf("%d\n", s.size());
    for (set<vector<int> >::iterator it = s.begin(); it != s.end(); ++it)
    {
        v = *it;
        for (int i = 0; i < n; ++i)
            printf("%d ", v[i]);
        printf("\n");
    }
}

int n;
int a[N], b[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    multiset<pair<int, int> > aa, bb;
    for (int i = 0; i < n; ++i)
    {
        aa.insert(m_p(min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])));
        bb.insert(m_p(min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1])));
    }
    if (aa == bb)
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    //por();
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}