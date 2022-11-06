#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

typedef long long int ll;

typedef vector<int> vei;
typedef vector<ll> vell;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d\n", a)
#define prisp(a) printf("%d ", a)

#define foi(n) for (int i = 0; i < n; ++i)
#define foj(n) for (int j = 0; j < n; ++j)

#define pb push_back

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()

#define openfiles(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll fact(int n) {
    ll res = 1;
    foi(n) res *= (i + 1);
    return res;
}

// File names!!!

int main() {
    // openfiles("test");
    int n;
    sci(n);
    vei a(n);
    foi(n) sci(a[i]);
    random_shuffle(all(a));
    sort(all(a));

    // ll ans = 0;
    // do {
    //  foi(n - 1) ans += abs(a[i] - a[i + 1]);
    //  ans += a[0];
    // } while (next_permutation(all(a)));

    ll ans = 0;
    ll sled = 0;
    foi(n) {
        ans += a[i];
        ans += abs(a[i] - a[0]);
        sled += abs(a[i] - a[0]);
    }
    // cerr << ans << endl;
    ll pr = 0;
    for (int i = 1; i < n; i++) {
        pr += (a[i] - a[i - 1] + 0LL) * (i);
        sled -= (a[i] - a[i - 1] + 0LL) * (n - i);
        // cerr << pr << " " << sled << endl;
        ans += pr + sled;
    }

    // n = fact(n);

    ll g = gcd(ans, n);
    ans /= g;
    cout << ans << " " << n / g;

    puts("");
    return 0;
}//pnohpi