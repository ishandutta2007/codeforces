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
#define forn(i, n) for (int i = 0; i < (n); i++)
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



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    h %= 12;
    t1 %= 12;
    t2 %= 12;
    int ph = h * 3600 + m * 60 + s;
    int pm = m * 60 * 12 + s * 12;
    int ps = s * 60 * 12;
    vector<int> f = {ph, pm, ps};

    int pt1 = t1 * 3600;
    int pt2 = t2 * 3600;

    
    if (pt1 > pt2) {
        swap(pt1, pt2);
    }
    bool type1 = 1;
    bool type2 = 1;
    for (auto x: f) {
        if (pt1 < x && x < pt2) {
            type1 = 0;
        }
        else {
            type2 = 0;
        }
    }

    if (type1 || type2) {
        puts("YES");
    }
    else {
        puts("NO");
    }




#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}