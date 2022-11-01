#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

ll a[N], add[N];

int main() {
    //ios_base::sync_with_stdio(false);
    //cout << fixed << setprecision(8);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, k, pos, x, typ;
    cin >> n;
    ll cur = 1, sum = 0;
    fr(i, n) {
        scanf("%I64d", &typ);
        if (typ == 1) {
            scanf("%I64d %I64d", &pos, &x);
            sum += pos * x;
            add[pos - 1] += x;
        }
        else if (typ == 2) {
            scanf("%I64d", &k);
            sum += k;
            a[cur++] = k;
        }
        else {
            sum -= a[--cur];
            sum -= add[cur];
            add[cur - 1] += add[cur];
            add[cur] = 0;
        }
        printf("%.10f\n", (double)sum / (double)cur);
    }
}