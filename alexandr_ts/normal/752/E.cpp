#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

int a[N];
//vector <int> b(M);
int b[M];

inline int f(int x, int m) {
    if (b[x])
        return b[x];
    if (x >= m && x < m + m) {
        b[x] = 1;
        return 1;
    }
    if (x < m)
        return 0;
    b[x] = f((x >> 1), m) + f(((x + 1) >> 1), m);
    return b[x];
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    fr(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    int l = 0, r = min((ll)a[0], sum / k) + 1;
    while (r - l > 1) {
        //fill(b, b + M, -1);
        memset(b, 0, sizeof(b));
        //fill(b.begin(), b.end(), -1);
        int m = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < n && cnt < k; i++)
            cnt += f(a[i], m);
        if (cnt >= k)
            l = m;
        else
            r = m;
    }
    if (l == 0)
        cout << -1;
    else
        cout << l;
}