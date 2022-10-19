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

int n, l, r;
int a[N];

int ql[N], qr[N];

void solv()
{
    cin >> n >> l >> r;

    for (int i = 1; i <= n; ++i)
    {
        ql[i] = qr[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= l; ++i)
        ql[a[i]]++;
    for (int i = l + 1; i <= n; ++i)
        qr[a[i]]++;

    for (int i = 1; i <= n; ++i)
    {
        if (ql[i] >= qr[i])
        {
            ql[i] -= qr[i];
            qr[i] = 0;
        }
        else
        {
            qr[i] -= ql[i];
            ql[i] = 0;
        }
    }

    int ans = 0;

    int qql = 0, qqr = 0;
    for (int i = 1; i <= n; ++i)
    {
        qql += ql[i];
        qqr += qr[i];
    }

    if (qql < qqr)
    {
        swap(qql, qqr);
        for (int i = 1; i <= n; ++i)
            swap(ql[i], qr[i]);
    }

    assert(qql >= qqr);
    {
        for (int i = 1; i <= n; ++i)
        {
            while (ql[i] >= 2)
            {
                if (qql == qqr)
                    break;
                ++ans;
                ql[i] -= 2;
                qql -= 2;
            }
        }
        ans += qql;
    }

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