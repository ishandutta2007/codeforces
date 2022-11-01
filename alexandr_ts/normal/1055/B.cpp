#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int MAX = 1e5 + 1;
const int N = 2e6 + 10;

ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    int x;
    fr(i, n) {
        scanf("%d", &x);
        a[i] = x;
    }

    int ans = 0;
    fr(i, n) {
        if ((!i || a[i - 1] <= l) && a[i] > l)
            ans++;
    }

    fr(i, m) {
        int typ;
        scanf("%d", &typ);
        if (!typ) {
            cout << ans << endl;
        } else {
            int p, d;
            scanf("%d %d", &p, &d);
            p--;
            bool ch = (a[p] <= l && a[p] + d > l);
            a[p] += d;
            if (!ch) continue;
            if (p && p + 1 < n && a[p - 1] > l && a[p + 1] > l) {
                ans--;
            } else {
                int cnt = 0;
                if (p && a[p - 1] > l)
                    cnt++;
                if (p + 1 < n && a[p + 1] > l)
                    cnt++;
                if (!cnt)
                    ans++;
            }

        }
    }
}