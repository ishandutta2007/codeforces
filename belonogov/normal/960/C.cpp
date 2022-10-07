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
    int x, d;
    scanf("%d%d", &x, &d);
    vector<ll> a;
    ll val = 1;
    ll step = 2e9;
    for (;x > 0;) {
        int k = 1;
        for (; pw((k + 1)) - 1 <= x; k++);

        x -= pw(k) - 1;
        for (int i = 0; i < k; i++) {
            a.pb(val);
        }
        val += step;
    } 

    cout << a.size() << endl;
    for (auto y: a) {
        cout << y << " ";
    }





    return 0;
}