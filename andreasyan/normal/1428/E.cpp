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

int n, k;
struct ban
{
    int x;
    int q;
    ban(){}
    ban(int x, int q)
    {
        this->x = x;
        this->q = q;
    }
};
ll clc(ban t)
{
    ll ans = (t.x / t.q + 1) * 1LL * (t.x / t.q + 1) * (t.x % t.q);
    ans += (t.x / t.q) * 1LL * (t.x / t.q) * (t.q - (t.x % t.q));
    return ans;
}
bool operator<(const ban& a, const ban& b)
{
    return (clc(a) - clc(ban(a.x, a.q + 1))) < (clc(b) - clc(ban(b.x, b.q + 1)));
}

void solv()
{
    scanf("%d%d", &n, &k);
    priority_queue<ban> q;
    for (int i = 1; i <= n; ++i)
    {
        ban t;
        scanf("%d", &t.x);
        t.q = 1;
        q.push(t);
    }
    for (int ii = 0; ii < k - n; ++ii)
    {
        ban t = q.top();
        q.pop();
        t.q++;
        q.push(t);
    }
    ll ans = 0;
    while (!q.empty())
    {
        ans += clc(q.top());
        q.pop();
    }
    printf("%lld\n", ans);
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