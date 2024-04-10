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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    ll ss = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        ss += a[i];
    }
    vector<int> mx(n);
    mx[0] = a[0];
    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i - 1], a[i]);
    }
    ll sum = 0;
    int res = mx[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1 && res > mx[i]) {
            res--;
        }
        sum += res;
    }

    cout << sum - ss << endl;






    return 0;
}