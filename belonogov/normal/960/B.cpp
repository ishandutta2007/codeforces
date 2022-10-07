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
    int n, k1, k2;
    scanf("%d", &n);
    scanf("%d%d", &k1, &k2);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] -= x;
    }
    for (int i = 0; i < n; i++) a[i] = abs(a[i]);
    int k = k1 + k2;
    for (;k > 0;k--) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > a[mx]) {
                mx = i;
            }
        }
        a[mx] = abs(a[mx] - 1); 
    }
    ll res = 0;
    for (auto x: a) {
        res += x * 1ll * x;
    }
    
    cout << res << endl;







    return 0;
}