#include<bits/stdc++.h>
#define x first
#define y second
#define size(a) (ll)(a).size()

typedef long long ll;
typedef long double ld;

using namespace std;
int n;
string s;


int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");


    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> s;

    vector<int> Num(n);

    bool zer = 1;
    for (int i = 0; i < n; i++)
    {
        Num[i] = (int)(s[i] - '0');

        if (Num[i] != 0)
        {
            zer = 0;
        }
    }

    if (zer)
    {
        cout << n;
        return 0;
    }

    bool cur = 0;

    for (int i = 0; i < n; i++)
    {
        cur ^= Num[i];
    }

    cur ^= 1;

    ll ans = 0;

    map<int, int> Was, Used;

    for (int i = 1; i < n; i++)
    {
        bool ok = 1;

        ll g = __gcd(n, i);

        if (Used[g])
        {
            ans += Was[g];
            continue;
        }

        Used[g] = 1;

        for (int j = 0; j < g; j++)
        {
            ll xur = 0;
            for (int k = j; k < n; k += g)
            {
                xur ^= Num[k];
            }

            if (xur == 1)
            {
                ok = 0;
                break;
            }
        }

        Was[g] = ok;

        ans += ok;

    }

    cout << ans;


}