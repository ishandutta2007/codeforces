#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
const int N = 100005;

int n, k;
int a[N];

struct ban
{
    int x;
    ban* u;
};

struct stackck
{
    ban* r;
    stackck()
    {
        r = nullptr;
    }
    void pop()
    {
        if (r == nullptr)
            return;
        ban* t = r->u;
        delete r;
        r = t;
    }
    void push(int x)
    {
        ban* t = new ban;
        t->x = x;
        t->u = r;
        r = t;
    }
    int top()
    {
        assert(r != nullptr);
        return r->x;
    }
    bool empty()
    {
        return (r == nullptr);
    }
};

stackck s[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        s[a[i]].push(a[i]);
    }

    int ans = a[n] - a[1];
    int minu = a[1];
    for (int maxu = a[n]; maxu >= 0; --maxu)
    {
        bool z = true;
        while (!s[maxu + 1].empty())
        {
            int x = s[maxu + 1].top();
            s[maxu + 1].pop();
            int u = x / (maxu + 1) + 1;
            if (u > k)
            {
                z = false;
                break;
            }
            s[x / u].push(x);
            minu = min(minu, x / u);
        }
        if (!z)
            break;
        ans = min(ans, maxu - minu);
    }

    for (int i = 0; i <= a[n]; ++i)
    {
        while (!s[i].empty())
            s[i].pop();
    }

    cout << ans << "\n";
}

int main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}