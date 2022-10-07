#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;



int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n, d, b;
    scanf("%d%d%d", &n, &d, &b);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    auto getSum = [&](int l, int r) {
        return pref[r] - pref[l];
    };
    int mid = (n + 1) / 2;
    ll need = 0;
    int r1 = 0;
    for (int i = 0; i < mid; i++) {
        ll cnt = i + 1;
        ll L = max(0ll, i - cnt * d);
        ll R = min(i + cnt * d, n - 1ll);
        ll sum = getSum(L, R + 1);
        need += b;
        ///db3(i, need, sum);
        //db2(L, R);
        if (sum < need) {
            need -= b;
            r1++;
        }
    }


    need = 0;
    int r2 = 0;
    for (int i = n - 1; i >= mid; i--) {
        ll cnt = n - i - 1 + 1;
        ll L = max(0ll, i - cnt * d);
        ll R = min(i + cnt * d, n - 1ll);
        ll sum = getSum(L, R + 1);
        need += b;
        if (sum < need) {
            need -= b;
            r2++;
        }
    }

//    db2(r1, r2);
    cout << max(r1, r2) << endl;



    return 0;
}