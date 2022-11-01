#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e6 + 10;
const int INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

int t[N], val[N];
int ans[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, q;
    cin >> n >> q;
    fr(i, q) {
        scanf("%d", &t[i]);
        //cin >> t[i];
        if (t[i] == 1)
            scanf("%d", &val[i]);
            //cin >> val[i];
    }

    int cur1 = 1, cur2 = 2;

    fr(i, q) {
        if (t[i] == 2) {
            if (cur1 % 2)
                cur1++;
            else
                cur1--;
            if (cur2 % 2)
                cur2++;
            else
                cur2--;
        }
        else {
            cur1 += val[i];
            if (cur1 > n)
                cur1 -= n;
            if (cur1 < 1)
                cur1 += n;

            cur2 += val[i];
            if (cur2 > n)
                cur2 -= n;
            if (cur2 < 1)
                cur2 += n;
        }
    }

    for (int i = 0; i < n / 2; i++) {
        ans[cur1] = 2 * i + 1;
        cur1 += 2;
        if (cur1 > n)
            cur1 -= n;
    }
    for (int i = 0; i < n / 2; i++) {
        ans[cur2] = 2 * i + 2;
        cur2 += 2;
        if (cur2 > n)
            cur2 -= n;
    }
    frab(i, 1, n + 1)
        printf("%d ", ans[i]);
}