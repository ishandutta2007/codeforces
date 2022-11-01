#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

struct tmp {
    int x, b;
} a[N];

bool cmp(tmp a, tmp b) {
    return a.b > b.b || a.b == b.b && a.x > b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i].x >> a[i].b;
    sort(a, a + n, cmp);
    int cur = 1;
    int ans = 0;
    fr(i, n)
        if (cur) {
            ans += a[i].x;
            cur += a[i].b - 1;
        }
        else break;
    cout << ans;
}