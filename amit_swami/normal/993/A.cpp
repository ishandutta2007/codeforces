#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

const int N = 222;
const int K = 111;

struct pt
{
    ll x, y;
    pt(){}
    pt(ll xx, ll yy): x(xx), y(yy) {}
    void read() { scanf("%lld%lld", &x, &y); }
};

inline pt operator + (pt p1, pt p2) { return pt(p1.x + p2.x, p1.y + p2.y); }
inline pt operator - (pt p1, pt p2) { return pt(p1.x - p2.x, p1.y - p2.y); }

inline ll vect(pt p1, pt p2) { return p1.x * p2.y - p1.y * p2.x; }



pt a[4];
pt b[4];

int main() {
#ifdef amit_swami
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    forn(i, 4) a[i].read();
    forn(i, 4) b[i].read();

    if (vect(a[1] - a[0], a[2] - a[0]) < 0) reverse(a, a + 4);
    if (vect(b[1] - b[0], b[2] - b[0]) < 0) reverse(b, b + 4);

    for (int x = -100; x <= 100; x++) for (int y = -100; y <= 100; y++) {
        pt p(x, y);
        int ok1 = 1;
        int ok2 = 1;
        forn(i, 4) {
            int j = (i + 1) % 4;
            ok1 &= vect(a[j] - a[i], p - a[i]) >= 0;
            ok2 &= vect(b[j] - b[i], p - b[i]) >= 0;
        }
        if (ok1 && ok2) return 0 * puts("YES");
    }
    puts("NO");

        



    return 0;
}