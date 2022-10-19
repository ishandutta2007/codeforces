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
ll x;
char a[N];
int q[26];


void solv()
{
    /*set<string> s[14];
    s[1].insert("+");
    for (int n = 2; n <= 13; ++n)
    {
        for (int m = 1; m < n; ++m)
        {
            for (auto it1 = s[m].begin(); it1 != s[m].end(); ++it1)
            {
                string u = "";
                for (int i = 0; i < sz(*it1); ++i)
                {
                    if ((*it1)[i] == '-')
                        u += '+';
                    else
                        u += '-';
                }
                for (auto it2 = s[n - m].begin(); it2 != s[n - m].end(); ++it2)
                {
                    s[n].insert(u + *it2);
                }
            }
        }
    }
    for (int n = 1; n <= 8; ++n)
    {
        cout << n << ' ' << sz(s[n]) << endl;
        for (auto it = s[n].begin(); it != s[n].end(); ++it)
            cout << *it << endl;
    }*/

    scanf("%d%lld", &n, &x);
    scanf(" %s", a);

    x -= (1 << (a[n - 1] - 'a'));
    x += (1 << (a[n - 2] - 'a'));
    x = abs(x);

    for (int i = 0; i < n - 2; ++i)
        q[a[i] - 'a']++;
    for (int i = 25; i >= 0; --i)
    {
        if (q[i] % 2 == 1)
        {
            x -= (1 << i);
            x = abs(x);
        }
        q[i] /= 2;

        while (1)
        {
            if (q[i] && abs(x - (1 << i) * 2) < abs(x))
            {
                x -= (1 << i) * 2;
                --q[i];
            }
            else
                break;
        }
        x = abs(x);
    }

    if (x == 0)
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}