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
string a;

void solv()
{
    cin >> n;
    cin >> a;

    int ans = N;
    for (char h = 'a'; h <= 'z'; ++h)
    {
        string b;
        vector<int> v;
        int q = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == h)
            {
                ++q;
                continue;
            }
            v.push_back(q);
            q = 0;
            b += a[i];
        }
        v.push_back(q);

        string c = b;
        reverse(all(c));
        if (b != c)
            continue;

        int yans = 0;
        for (int i = 0; i < sz(v) / 2; ++i)
            yans += abs(v[i] - v[sz(v) - i - 1]);

        ans = min(ans, yans);
    }

    if (ans == N)
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
        solv();
    return 0;
}