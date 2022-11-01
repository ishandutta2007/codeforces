#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const ll INF = 2e12 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    set <int> s;
    int ans = 0, cnt = 0;
    fr(i, 2 * n) {
        int x;
        cin >> x;
        if (a[x])
            a[x]--, cnt--;
        else
            a[x]++, cnt++;
        ans = max(ans, cnt);
    }
    cout << ans;
}