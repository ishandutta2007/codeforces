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


struct pt {
    int x, y;
    int d(pt A) {
        return abs(x - A.x) + abs(y - A.y);
    }
    void read() {
        scanf("%d%d", &x, &y);
    }
};

int sign(int x) {
    if (x == 0) return 0;
    if (x < 0) return -1;
    if (x > 0) return 1;
    assert(false);
}

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    pt a[3];
    for (int i = 0; i < 3; i++) {
        a[i].read();
    }
    int answer = INF;
    int wx = -1, wy = -1;
    for (int x = 0; x <= 1000; x++) {
        for (int y = 0; y <= 1000; y++) {
            int tmp = 0;
            for (int i = 0; i < 3; i++) {
                tmp += a[i].d({x, y});
            }
            if (answer > tmp) {
                answer = tmp;
                wx = x;
                wy = y;
            }
        }
    }
    set<pair<int,int>> path;
    for (int i = 0; i < 3; i++) {
        int dx = sign(a[i].x - wx);
        int dy = sign(a[i].y - wy);

        int cur_x = wx;
        int cur_y = wy;
        for (; cur_x != a[i].x; cur_x += dx) path.insert({cur_x, cur_y});
        for (; cur_y != a[i].y; cur_y += dy) path.insert({cur_x, cur_y});
        path.insert({cur_x, cur_y});
    }




    assert((int)path.size() == answer + 1);
    cout << path.size() << endl;
    for (auto x: path) {
        cout << x.F << " " << x.S << endl;
    }






    return 0;
}