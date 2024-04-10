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

int ask(int w)
{
    cout << "? " << w << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    int n;
    cin >> n;
    int l = 2 * n - 1, r = n * 2000 + n - 1, best = r;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ask(mid) == 1) best = mid, r = mid - 1;
        else l = mid + 1;
    }
    int sum = best - (n - 1);
    for (int i = 2; i <= n; ++i)
    {
        int w = (best - 1) / i;
        if (w * i < sum) continue;
        int h = ask(w);
        if (h != 0 && h * w < best) best = h * w;
    }
    cout << "! " << best << endl;
    return 0;
}