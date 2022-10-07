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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const long long INF = 1e17;
const int T = 1e4;

bool equal(double a, double b) {
    return abs(a - b) < 1e-9;
} 

bool less(double a, double b) {
    return a < b && !equal(a, b);
}

bool lessE(double a, double b) {
    return a < b || equal(a, b);
}

struct pnt {
    double x, y;
    int id;
    pnt () { }
    pnt (double x, double y): x(x), y(y) { } 
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator * (double k) {
        return pnt(x * k, y * k); 
    }
    double operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    bool operator == (pnt A) {
        return equal(x, A.x) && equal(y, A.y);
    }
    bool operator != (pnt A) {
        return !equal(x, A.x) || !equal(y, A.y);
    }
    
    double len2() {
        return x * x + y * y;
    }
    void Epr() {
        int T = 1e4;
        epr("(%.5lf %.5lf)      \t\t real %d %d \n", x * T, y * T, (int)round(1 / x), (int)round(1 / y));
    }
};

int n;
pnt p[N];
map < pair < int, int >, vector < int > > q;
pair < int, int > in[N];
pnt O;



void read() {
    scanf("%d", &n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        in[i] = mp(x, y);
        q[mp(x, y)].pb(i);
        if ((int)q[mp(x, y)].size() == 1)
            p[cur++] = pnt(1.0 / x, 1.0 / y);
    } 
    n = cur;
    for (int i = 0; i < n; i++)
        p[i] = p[i] * T;
    //cerr << "n: " << n << endl;
}


bool cmpO(pnt A, pnt B) {
    A = A - O;
    B = B - O;
    return less(0, A * B) || (equal(A * B, 0) && A.len2() < B.len2());
}


void convexHull() {
    for (int i = 0; i < n; i++)
        if (less(p[i].x, p[0].x) || (equal(p[0].x, p[i].x) && less(p[i].y, p[0].y)))
            swap(p[i], p[0]);

    O = p[0];
    sort(p + 1, p + n, cmpO);

    //int M = 10;
    //for (int i = 0; i < M; i++)
        //p[i].Epr();
    //vector < pnt > h; 
    //for (int i = 0; i < n; i++)
        //h.pb(p[i]);
    //sort(p + 1, p + n, cmpO);
    //for (int i = 0; i < n; i++)
        //assert(p[i] == h[i]);


    int cur = 0;
    //cerr << "n: " << n << endl;
    for (int i = 0; i < n; i++) {
        for (; cur >= 2 && less((p[cur - 1] - p[cur - 2]) * (p[i] - p[cur - 1]), 0); cur--);
        p[cur++] = p[i];
        //for (;;) {
            //if (cur < 2) break;
            //pnt r1 = (p[cur - 1] - p[cur - 2]);
            //pnt r2 = (p[i] - p[cur - 1]);
            //double r3 = r1 * r2;
            //if (less(r3, 0)) {
                //cur--;
            //}  
            //else
                //break;
        //}
        //p[cur++] = p[i];
    }
    //cerr << "cur: " << cur << endl;
    n = cur;
    for (int i = 1; i < n; i++) {
        if (lessE(p[i - 1].y, p[i].y)) {
            n = i;
            break;
        }
    }  
}

void solve() {
    //for (int i = 0; i < n; i++)
        //for (int j = 0; j < n; j++) {
            //if (i == j) continue;
            ////cerr << "i j: " << i << " " << j << endl;
            //assert(p[i] != p[j]);
            ////assert(in[i] != in[j]);
        //}
    convexHull();
    vector < int > res;
    for (int i = 0; i < n; i++) {
        auto pr = mp((int)round(1 / p[i].x * T), (int)round(1 / p[i].y * T));
        assert((int)q[pr].size() > 0);
        vector < int > g = q[pr];
        for (auto x: g)
            res.pb(x);
        //for (auto x: g)
            //cerr << in[x].fr << " " << in[x].sc << endl;

    }
    sort(res.begin(), res.end());
    for (auto x: res)
        printf("%d ", x + 1);
    printf("\n");
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    //cerr << "---\n";
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("test.txt", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}