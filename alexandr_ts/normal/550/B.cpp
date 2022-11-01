#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define read(a) scanf("%d", &a)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

int a[N];

bool chck1(int mask) {
    return __builtin_popcount(mask) >= 2;
}

bool chck2(int mask, int n, int l, int r) {
    int sum = 0;
    fr(i, n)
        if ((1 << i) & mask)
            sum += a[i];
    return sum >= l && sum <= r;
}

bool chck3(ll mask, int n, int x) {
    int mx = -INF, mn = INF;
    fr(i, n)
        if ((1 << i) & mask)
            mx = max(mx, a[i]), mn = min(mn, a[i]);
    return mx - mn >= x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n, l, r, x;
    scanf("%d %d %d %d ", &n, &l, &r, &x);
    fr(i, n)
        scanf("%d", &a[i]);
    int ans = 0;
    fr(mask, (1 << n)) {
        //cout << mask << " " << chck1(mask) << chck2(mask, n, l, r) << chck3(mask, n, x) << endl;
        if (chck1(mask) && chck2(mask, n, l, r) && chck3(mask, n, x))
            ans++;
    }
    cout << ans;
}