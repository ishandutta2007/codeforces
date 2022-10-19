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

vector<int> v;
map<int, bool> mp;

bool solv(int n)
{
    if (mp.find(n) != mp.end())
        return mp[n];
    if (n == 1)
        return mp[n] = false;
    if (n % 2 == 1)
        return mp[n] = true;
    if (n == 2)
        return mp[n] = true;
    for (int i = 0; i < v.size(); ++i)
    {
        if (n % v[i] == 0)
        {
            if (!solv(n / v[i]))
                return mp[n] = true;
        }
    }
    return mp[n] = false;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        v.clear();
        mp.clear();
        int n;
        scanf("%d", &n);
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                if (i > 1 && i % 2 == 1)
                    v.push_back(i);
                if ((n / i) > 1 && (n / i) % 2 == 1)
                    v.push_back((n / i));
            }
        }
        if (solv(n))
            printf("Ashishgup\n");
        else
            printf("FastestFinger\n");
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}