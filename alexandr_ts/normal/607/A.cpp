#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e6 + 10;
const ll MOD = 1e9 + 7;

struct pt {
    int x, y;
} a[N];

bool cmp(pt a, pt b) {
    return a.x < b.x;
}

int d[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i].x >> a[i].y;
    sort(a, a + n, cmp);
    d[0] = 1;
    if (n >= 2) {
        if (a[1].x - a[0].x > a[1].y)
            d[1] = 2;
        else
            d[1] = 1;
    }
    frab(i, 2, n) {
        int l = 0, r = i;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[i].x - a[m].x > a[i].y)
                l = m;
            else
                r = m;
        }
        //cout << i << " " << r << endl;
        //d[i] = d[i - 1];
        if (a[i].x - a[r - 1].x > a[i].y)
            d[i] = max(d[i], d[r - 1] + 1);
        else
            d[i] = 1;
    }
    //fr(i, n)
      //  cout << d[i] << " ";cout << endl;
    int mx = *max_element(d, d + n);
    cout << n - mx << endl;

}