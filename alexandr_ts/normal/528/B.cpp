#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1000;
const ll INF = 200000000000000000ll;
struct tn
{
    ll x;
    bool st;
};

vector <pair<ll, ll> > a;

//int d[N];

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first < b.first || a.first == b.first && a.second < b.second;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ll n, t1, t2;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        a.push_back(mp(t1 - t2, t1 + t2));
    }
    sort(a.begin(), a.end(), cmp);

    vector <ll> d(n + 1);
    d[0] = -INF;
    for (ll i = 1; i <= n; i++)
        d[i] = INF;

    for (ll i = 0; i < n; i++)
    {
        ll j = ll(upper_bound(d.begin(), d.end(), a[i].first) - d.begin());
        if (d[j - 1] <= a[i].first && a[i].second < d[j])
            d[j] = a[i].second;
    }
    for (ll i = n; i >= 0; i--)
        if (d[i] != INF)
    {
        cout << i;
        return 0;
    }

}