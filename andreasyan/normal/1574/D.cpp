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
const int N = 11;

int n;
vector<int> a[N];

struct ban
{
    vector<int> u;
    ban()
    {
        u.assign(n, 0);
    }
    int sum() const
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += a[i][u[i]];
        return ans;
    }
};

bool operator<(const ban& a, const ban& b)
{
    return a.sum() < b.sum();
}

void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    set<vector<int> > s;

    int m;
    cin >> m;
    while (m--)
    {
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            --x;
            v.push_back(x);
        }
        s.insert(v);
    }

    priority_queue<ban> q;
    ban t;
    for (int i = 0; i < n; ++i)
        t.u[i] = sz(a[i]) - 1;
    q.push(t);

    set<vector<int> > c;
    while (!q.empty())
    {
        ban t;
        do
        {
            t = q.top();
            q.pop();
        } while (c.find(t.u) != c.end());
        c.insert(t.u);

        if (s.find(t.u) == s.end())
        {
            //cout << t.sum() << "\n";
            for (int i = 0; i < sz(t.u); ++i)
                cout << t.u[i] + 1 << ' ';
            cout << "\n";
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            ban h = t;
            if (h.u[i])
            {
                --h.u[i];
                q.push(h);
            }
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}