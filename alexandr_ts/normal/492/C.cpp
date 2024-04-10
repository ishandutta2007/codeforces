#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e9 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

struct tmp {
    ll a, b;
};

tmp a[N];

bool cmp(tmp a, tmp b) {
    return a.b < b.b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ll n, r, avg, sum = 0;
    cin >> n >> r >> avg;
    fr(i, n) {
        cin >> a[i].a >> a[i].b;
        sum += a[i].a;
    }
    sort(a, a + n, cmp);
    ll ans = 0;
    for (int i = 0; i < n && sum < n * avg; i++) {
        ll qua = r - a[i].a;
        if (sum + qua <= n * avg) {
            sum += qua;
            ans += qua * a[i].b;
        }
        else {
            ans += (n * avg - sum) * a[i].b;
            sum = n * avg;
        }
    }
    cout << ans;
}