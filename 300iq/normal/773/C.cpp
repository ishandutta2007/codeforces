#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const ld EPS = 1e-9;

const ll llinf = 1e18 + 100;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

int d[42], q[42], ds[42];

int n;

ll a[maxn];

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
	    #ifndef STR
	    //ifstream cin("a.in");
	    //ofstream cout("a.out");
	    //freopen("a.in", "r", stdin);
	    //freopen("a.out", "w", stdout);
    	    #endif // STR
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    int sz = 0;
    for (int i = 0; i < n; i++){
        ll x, k = 0, st = 1;
        cin >> x;
        while (x % 2 == 0)
            k++, x /= 2, st *= 2;
        if (x == 1)
            d[k]++;
        else
            a[sz] = x * st, sz++;
    }
    for (int i = 0; i < sz; i++){
        for (ll j = 0, st = 1; ; j++, st *= 2){
            if (st > a[i]){
                q[j - 1]++;
                break;
            }
        }
    }
    for (int i = 0; i < 42; i++)
        ds[i] = d[i];
    int now = 0;
    int ans = 0;
    int l = 0, r = d[0] + 1;
    while (r - l > 1){
        int m = (l + r) / 2;
        int s = m;
        bool is = 1;
        int rm = d[0] - s;
        d[0] = s;
        for (int i = 0; i <= 40; i++){
            rm += q[i];
            rm += max(0, d[i + 1] - d[i]);
            d[i + 1] = min(d[i + 1], d[i]);
            rm = max(0, rm - max(0, d[i] - d[i + 1]));
        }
        if (rm == 0)
            r = m;
        else
            l = m;
        for (int i = 0; i < 42; i++)
            d[i] = ds[i];
    }
    if (r > d[0])
        cout << -1;
    else
    for (int i = r; i <= d[0]; i++)
        cout << i << ' ';
}