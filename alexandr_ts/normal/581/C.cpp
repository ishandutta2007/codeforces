#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 2 * 1e6;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

ll a[N];
vector <ll> ans;

bool cmp(int a, int b) {
    return a % 10 > b % 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
//freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n, cmp);
    int ans = 0;
    fr(i, n)
        while (a[i] % 10)
            if (k && a[i] < 100) a[i]++, k--;
            else break;
    fr(i, n)
        while (a[i] < 91)
            if (k >= 10)
                a[i] += 10, k -= 10;
            else
                break;
    fr(i, n)
        ans += a[i] / 10;
    cout << ans;
}