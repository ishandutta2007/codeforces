#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

pair <int, int> a[N];

bool cmp(pair <int, int> a, pair <int, int> b) {
    return a.second - a.first > b.second - b.first;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i].first;
    fr(i, n)
        cin >> a[i].second;
    sort(a, a + n, cmp);
    ll ans = 0;
    fr(i, n) {
        if (i < k || a[i].first < a[i].second)
            ans += a[i].first;
        else
            ans += a[i].second;
    }
    cout << ans;
}