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

void solv()
{
    ll w, h;
    cin >> w >> h;

    vector<int> x1, x2;
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        x1.push_back(x);
    }

    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        x2.push_back(x);
    }

    vector<int> y1_, y2;
    cin >> q;
    while (q--)
    {
        int y;
        cin >> y;
        y1_.push_back(y);
    }

    cin >> q;
    while (q--)
    {
        int y;
        cin >> y;
        y2.push_back(y);
    }

    ll ans = max(max((x1.back() - x1[0]) * h, (x2.back() - x2[0]) * h),
                  max((y1_.back() - y1_[0]) * w, (y2.back() - y2[0]) * w));

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