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
const int N = 10004;
struct ban
{
    int x, y;
    ban()
    {
        x = y = 0;
    }
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}

int n;
ban a[N];

vector<ban> ans;

void rec(int l, int r)
{
    if (l == r)
    {
        ans.push_back(a[l]);
        return;
    }
    int m = (l + r) / 2;
    rec(l, m);
    rec(m + 1, r);
    for (int i = l; i <= r; ++i)
    {
        ans.push_back(ban(a[m].x, a[i].y));
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1);
    rec(1, n);
    sort(all(ans));
    vector<ban> yans;
    for (int i = 0; i < ans.size(); ++i)
    {
        if (!i || !(ans[i].x == ans[i - 1].x && ans[i].y == ans[i - 1].y))
            yans.push_back(ans[i]);
    }
    ans = yans;
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].x, ans[i].y);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}