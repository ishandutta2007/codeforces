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
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
typedef long double dbl;
typedef long long ll;
const int N = 1111;
const ll INF = 1.01e9;
typedef vector<int> vi;

struct pt {
    int x, y;
    pt () { }
    pt (int xx, int yy): x(xx), y(yy) {}
    pt operator + (pt A) {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) {
        return pt(x - A.x, y - A.y);
    }
    pt operator * (int k) {
        return pt(x * k, y * k);
    }
    pt rotate() {
        return pt(-y, x);
    }
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m;
char s[N][N];
bool can[N][N];

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    
    pt S, T;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S') {
                S = pt(i, j);
            }
            if (s[i][j] == 'T') {
                T = pt(i, j);
            }
        }
    }


    for (int t = 0; t < 4; t++) {
        pt dir(dx[t], dy[t]);
        for (int i = 1; ; i++) {
            pt A = dir * i + T;
            if (check(A.x, A.y) && s[A.x][A.y] != '*') {
                pt dd = dir.rotate();
                for (int g = 0; g < 2; g++) {
                    for (int j = 0; ; j++) {
                        pt B = A + dd * j;
                        if (check(B.x, B.y) && s[B.x][B.y] != '*') {
                            can[B.x][B.y] = 1;
                        }
                        else
                            break;
                    }
                    dd = dd * -1;
                }
            }
            else
                break;
        }

    } 

    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < m; j++)
            //cerr << can[i][j] << " ";

    
    
    for (int t = 0; t < 4; t++) {
        pt dir(dx[t], dy[t]);
        for (int i = 0; ; i++) {
            pt A = dir * i + S;
            //db2(A.x, A.y);
            if (check(A.x, A.y) && s[A.x][A.y] != '*') {
                if (can[A.x][A.y]) {
                    puts("YES");
                    return 0;
                }
            }
            else
                break;
        }
    }
    puts("NO");
    return 0;
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}