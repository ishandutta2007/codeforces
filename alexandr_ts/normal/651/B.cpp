#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;

int a[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n;
    cin >> n;
    map <int, int> m;
    fr(i, n) {
        cin >> a[i];
        m[a[i]]++;
    }
    int ans = 0;
    frab(i, 1, n + 1) {
        int cnt = 0;
        for (auto it: m)
            if (it.second >= i)
                cnt++;
        ans += max(0, cnt - 1);
    }
    cout << ans;
}