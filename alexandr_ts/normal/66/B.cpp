#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const int MOD = 1e9 + 7;

int a[N];

int main() {
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int ans = 0;
    fr(i, n) {
        int l = i, r = i;
        while (l > 0 && a[l - 1] <= a[l])
            l--;
        while (r < n - 1 && a[r + 1] <= a[r])
            r++;
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}