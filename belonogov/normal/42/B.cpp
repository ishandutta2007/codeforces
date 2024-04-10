#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;

struct pt {
    int x, y;
    pt () {}
    pt (int xx, int yy): x(xx), y(yy) {}
    pt operator + (pt A) {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) {
        return pt(x - A.x, y - A.y);
    }
};

void read(int& x, int& y) {
    string s;
    cin >> s;
    assert(s.size() == 2);
    x = s[0] - 'a';
    y = s[1] - '1';
}

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    vector<pt> rook;

    int x, y;
    read(x, y);
    rook.pb({x, y});

    read(x, y);
    rook.pb({x, y});
    
    read(x, y);
    pt W(x, y);
    read(x, y);
    pt B(x, y);

    vector<vector<int>> board(8, vector<int>(8));
    auto used = board;
    used[rook[0].x][rook[0].y] = 1;
    used[rook[1].x][rook[1].y] = 1;
    used[W.x][W.y] = 1;


    vector<pt> dr = {pt(0, 1), pt(1, 0), pt(-1, 0), pt(0, -1)};
    vector<pt> dk;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0) {
                dk.pb(pt(dx, dy));
            }
        }
    }

    auto check = [&](pt A) {
        return 0 <= A.x && A.x < 8 && 0 <= A.y && A.y < 8;
    };

    for (auto r: rook) {
        for (auto dir: dr) {
            pt A = r + dir;        
            for (;check(A); A = A + dir) {
                board[A.x][A.y] = 1; 
                if (used[A.x][A.y]) {
                    break;
                }
            }
        }
    }

    //db(dk.size());
    for (auto dir: dk) {
        pt A = W + dir;
        //db2(A.x, A.y);
        if (check(A)) {
            //db2(A.x, A.y);
            board[A.x][A.y] = 1;
        }
    }
    bool ok = 1;
    dk.pb({0, 0});
    for (auto dir: dk) {
        pt A = dir + B;
        if (check(A) && board[A.x][A.y] == 0) {
            //db2(A.x, A.y);
            ok = 0;
        }
    }
    //for (int i = 0; i < 8; i++, cerr << endl) {
        //for (int j = 0; j < 8; j++) {
            //cerr << board[i][j] << " ";
        //}
    //}
    if (ok) {
        puts("CHECKMATE");
    }
    else {
        puts("OTHER");
    }












   
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}