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
char a[N], b[N];

void solv()
{
    cin >> n;
    cin >> a;
    cin >> b;

    int ans = 0;
    vector<char> v;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i] == '0' || v[i] == '2')
                    ++ans;
                else if (v[i] == '1')
                {
                    if (i - 1 >= 0 && v[i - 1] == '0')
                    {
                        ++ans;
                        v[i - 1] = '2';
                    }
                    else if (i + 1 < sz(v) && v[i + 1] == '0')
                    {
                        ++ans;
                        v[i + 1] = '2';
                    }
                }
            }
            ans += 2;
            v.clear();
        }
        else
            v.push_back(a[i]);
    }
    for (int i = 0; i < sz(v); ++i)
            {
                if (v[i] == '0' || v[i] == '2')
                    ++ans;
                else if (v[i] == '1')
                {
                    if (i - 1 >= 0 && v[i - 1] == '0')
                    {
                        ++ans;
                        v[i - 1] = '2';
                    }
                    else if (i + 1 < sz(v) && v[i + 1] == '0')
                    {
                        ++ans;
                        v[i + 1] = '2';
                    }
                }
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
        solv();
    return 0;
}