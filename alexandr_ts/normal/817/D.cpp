#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 7;
const int M = 1e3 + 5;
const int N = 1e6 + 5;
const int POW = 20;
const ll MOD = 1000 * 1000 * 1000 + 7;

int a[N];

ll cntMax(int n) {
    vector <pair <int, int> > v;
    ll ans = 0;
    ll cursum = 0;
    fr(i, n) {
        v.pb(mp(a[i], 1));
        cursum += a[i];
        while (v.size() >= 2 && v.back().first > v[(int)v.size() - 2].first) {
            int j = (int)v.size() - 2;
            cursum += (ll)v[j].second * (ll)(v.back().first - v[j].first);
            v[j].first = v.back().first;
            v[j].second += v.back().second;
            v.pop_back();
        }
        ans += cursum;
    }
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    fr(i, n) {
        scanf("%d", &a[i]);
    }
    ll sumMax = cntMax(n);
    fr(i, n)
        a[i] = -a[i];
    ll sumMin = -cntMax(n);
    cout << sumMax - sumMin;
}