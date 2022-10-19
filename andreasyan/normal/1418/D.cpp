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

set<int> s;
multiset<int> ss;

void ave(int x)
{
    if (s.empty())
    {
        s.insert(x);
        return;
    }
    auto it = s.upper_bound(x);
    if (it == s.end())
    {
        ss.insert(x - *(--s.end()));
        s.insert(x);
        return;
    }
    if (it == s.begin())
    {
        ss.insert(*s.begin() - x);
        s.insert(x);
        return;
    }
    auto it0 = it;
    --it0;
    ss.erase(ss.find(*it - *it0));
    ss.insert(x - *it0);
    ss.insert(*it - x);
    s.insert(x);
    return;
}

void han(int x)
{
    s.erase(x);
    if (s.empty())
        return;
    auto it = s.upper_bound(x);
    if (it == s.end())
    {
        ss.erase(ss.find(x - *(--s.end())));
        return;
    }
    if (it == s.begin())
    {
        ss.erase(ss.find(*s.begin() - x));
        return;
    }
    auto it0 = it;
    --it0;
    ss.insert(*it - *it0);
    ss.erase(ss.find(x - *it0));
    ss.erase(ss.find(*it - x));
    return;
}

int ver()
{
    if (sz(s) <= 2)
        return 0;
    return *(--s.end()) - *s.begin() - *(--ss.end());
}

void solv()
{
    int n, q;
    scanf("%d%d", &n, &q);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        ave(x);
    }
    printf("%d\n", ver());
    while (q--)
    {
        int ty, x;
        scanf("%d%d", &ty, &x);
        if (ty == 0)
            han(x);
        else
            ave(x);
        printf("%d\n", ver());
    }
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