#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-10;

ld mn[N], mx[N];
ld a[N], b[N], prefa[N], prefb[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n) {
        double t;
        scanf("%lf", &t);
        mx[i] = t;
    }
    fr(i, n) {
        double t;
        scanf("%lf", &t);
        mn[i] = t;
    }

    fr(i, n) {
        ld t = mx[i] + mn[i];
        ld D = (t + prefa[i] - prefb[i]) * (t + prefa[i] - prefb[i]) - 4 * (mx[i] - t * prefb[i]);
        //assert(D > -EPS);
        b[i] = ((t + prefa[i] - prefb[i]) + sqrt(max((ld)0, D))) / 2;
        a[i] = t - b[i];
        prefa[i + 1] = prefa[i] + a[i];
        prefb[i + 1] = prefb[i] + b[i];
    }
    cout << fixed << setprecision(6);
    fr(i, n)
         cout << a[i] << " ";
    cout << endl;
    fr(i, n)
        cout << b[i] << " ";
}