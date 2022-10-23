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

int ask(vi vt)
{
    cout << "? ";
    for (int x : vt) cout << x << " ";
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int d[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    int n;
    cin >> n;
    int flag = 0, an = n;
    for (int i = 1; i < n; ++i)
    {
        vi vt(n, i);
        vt[n - 1] = n;
        int v = ask(vt);
        if (v)
        {
            if (!flag) an = i;
            flag = 1;
            d[v] = n - i;
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        vi vt(n, i);
        vt[n - 1] = 1;
        int v = ask(vt);
        if (v) d[v] = 1 - i;
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i) cout << an + d[i] << " ";
    cout << endl;
    return 0;
}