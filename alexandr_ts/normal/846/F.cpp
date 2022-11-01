#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1003;
const int N = 1e6 + 10;

ll a[N];
ll cnt[N], cnt2[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    map <int, int> m;
    fr(i, n) {
        scanf("%d", &a[i]);
//        if (!m.count(a[i]))
//            cnt[i] = i + 1;
//        else
//            cnt[i] = i - m[a[i]];
//        m[a[i]] = i;
        cnt[i] = i + 1;
    }

    m.clear();
    for (int i = n - 1; i >= 0; i--) {
        if (!m.count(a[i]))
            cnt2[i] = n - i;
        else
            cnt2[i] = m[a[i]] - i;
        m[a[i]] = i;
    }

    ll sum = 0;
    fr(i, n)
        sum += (cnt[i] * cnt2[i] * 2 - 1);
    //cout << sum << endl;
    cout << fixed << setprecision(12) << (ld)sum / ((ld)n * n);

}