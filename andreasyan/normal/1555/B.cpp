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
const int INF = 1000000009;

int stg(int W, int H, int x1, int y1_, int x2, int y2, int w, int h)
{
    assert(x1 < x2);
    assert(y1_ < y2);

    if (!(x1 < w && y1_ < h))
        return 0;

    int ans = INF;
    if (x2 + (w - x1) <= W)
        ans = min(ans, w - x1);
    if (y2 + (h - y1_) <= H)
        ans = min(ans, h - y1_);

    return ans;
}

void solv()
{
    int W, H, x1, y1_, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1_ >> x2 >> y2 >> w >> h;

    int ans = INF;
    ans = min(ans, stg(W, H, x1, y1_, x2, y2, w, h));
    ans = min(ans, stg(W, H, W - x2, y1_, W - x1, y2, w, h));
    ans = min(ans, stg(W, H, x1, H - y2, x2, H - y1_, w, h));
    ans = min(ans, stg(W, H, W - x2, H - y2, W - x1, H - y1_, w, h));

    if (ans == INF)
        cout << "-1\n";
    else
        cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}