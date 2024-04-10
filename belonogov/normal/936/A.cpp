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
    ll k, d, t;
    cin >> k >> d >> t;
    t *= 2;
    ll tmr = (k + d - 1) / d;
    d *= tmr;
    ll eff = k * 2 + (d - k);
    ll full = t / eff;
    dbl answer = full * d;
    t %= eff;
    if (t <= k * 2) {
        answer += t / 2.0;
    }
    else {
        answer += k;
        t -= k * 2;
        answer += t;
    }
    printf("%.17f\n", answer);











    return 0;
}