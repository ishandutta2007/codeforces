#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10;

int ask(int x)
{
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
}

int p[N], vis[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) vis[i] = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
            {
                int prv = ask(i);
                vis[prv] = 1;
                int x = ask(i);
                while (!vis[x])
                {
                    p[prv] = x;
                    prv = x;
                    vis[prv] = 1;
                    x = ask(i);
                }
                p[prv] = x;
            }
        cout << "! ";
        for (int i = 1; i <= n; ++i) cout << p[i] << " ";
        cout << endl;
    }
    return 0;
}