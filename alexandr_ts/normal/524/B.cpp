#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 1001;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

ll a[N], b[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i] >> b[i];
    int ans = INF;
    frab(h, 1, M) {
        bool ok = true;
        int sumw = 0;
        fr(i, n) {
            if (a[i] > h && b[i] > h)
                ok = false;
            if (a[i] <= h && b[i] <= h)
                sumw += min(a[i], b[i]);
            else if (a[i] <= h)
                sumw += b[i];
            else
                sumw += a[i];
        }
        if (ok)
            ans = min(ans, sumw * h);
    }
    cout << ans;

}