#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

struct pt {
    ll x, y;
};


int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<pt> p(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }

    sort(all(p), [](pt A, pt B) {
        return A.x < B.x || (A.x == B.x && A.y < B.y);
    });


    vector<pt> st;

    for (int i = 0; i < n;) {
        int j = i;
        for (; i < n && p[j].x == p[i].x; i++);
        for (;st.size() >= 2; ) {
            pt A = st[st.size() - 2];
            pt B = st[st.size() - 1];
            pt C = p[i - 1];

            ll lval = B.x * B.x * (C.x - A.x) + B.x * (C.y + A.x * A.x - A.y - C.x * C.x) +
                    C.x * A.y - C.y * A.x - C.x * A.x * A.x + C.x * C.x * A.x;
            ll rval = B.y * (C.x - A.x);

            if (lval >= rval) {
                st.pop_back();
            }
            else{
                break;
            }
        }
        st.push_back(p[i - 1]);
    }


    cout << (int)st.size() - 1 << endl;


    return 0;
}