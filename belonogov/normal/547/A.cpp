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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 

#define equal equalll
#define less lesss
#define x1 x111
#define y1 y111
const int N = -1;
const int INF = 1e9;
long long MOD;

void upd(long long & a, long long b) {
    a = (a + b) % MOD;
}

struct matrix {
    vector < vector < long long > > data;
    int sz;
    matrix(int sz):sz(sz) {
        data.assign(sz, vector < long long >(sz, 0));
    }
    matrix operator * (matrix A) {
        matrix res(sz);
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < sz; k++) {
                    upd(res.data[i][j], data[i][k] * A.data[k][j]);
                }
        return res;
    }
};

long long h1, a1, x1, y1;
long long h2, a2, x2, y2;

void read() {
    cin >> MOD;
    cin >> h1 >> a1;
    cin >> x1 >> y1;

    cin >> h2 >> a2;
    cin >> x2 >> y2; 
}

matrix binPow(matrix a, int b) {
    matrix c(2);
    c.data[0][0] = 1;
    c.data[1][1] = 1;
    for (; b > 0; b /= 2) {
        if (b & 1)
            c = c * a;
        a = a * a;
    }
    return c;
}

long long solve() {
    vector < long long > g;
    int fStep = -1;
    long long H1 = h1;
    for (int i = 0; i < MOD * 2 + 1; i++) {
        if (fStep == -1 && H1 == a1) {
            fStep = i;
        }
        g.pb(H1);
        H1 = (H1 * x1 + y1) % MOD;
    }
    if (fStep == -1) {
        return   -1;
    }
    long long val = g.back();
    long long circle = -1;
    //for (auto x: g)
        //cerr << x << " ";
    //cerr << endl;
    for (int i = (int)g.size() - 2; i >= 0; i--) {
        if (g[i] == val) {
            circle = ((int)g.size() - 1) - i;
            break;
        }
    }
    //db2(fStep, circle);
    assert(circle != -1);
    matrix c(2);
    c.data[0][0] = x2;
    c.data[1][0] = y2;
    c.data[1][1] = 1; 


    matrix d = c;
    matrix cc = c;
    d = binPow(d, fStep); // fstep;
    c = binPow(c, circle); // cricle
    matrix zero(2);
    zero.data[0][0] = h2;
    zero.data[0][1] = 1;

    matrix dd = binPow(cc, 3);
    //cerr << (zero * dd).data[0][0] << endl;
    //for (int i = 0; i < 5; i++) {
        //cerr << zero.data[0][0] << endl;
        //zero = zero * cc;
    //}
     


     
    zero = zero * d;

    assert(g[fStep] == a1);
    if (g[fStep + circle] != a1) {
        if (zero.data[0][0] == a2) {
            return fStep;
        }
        return -1;
    } 


    for (int i = 0; i < MOD; i++) {
        //db2(zero.data[0][0], a2);
        
        if (zero.data[0][0] == a2) {
            return fStep + i * 1ll * circle;
        }
        zero = zero * c;
    }
    return -1;
}

void printAns() {

}

int stupid() {
    long long H1 = h1;
    long long H2 = h2;
    int answer = 0;
    for (int i = 0; i < MOD * MOD; i++) {
        //db2(H1, a1);
        if (H1 == a1 && H2 == a2) return answer;
        H1 = (H1 * x1 + y1) % MOD;
        H2 = (H2 * x2 + y2) % MOD;
        answer++;
    }
    return -1;
}
void printTest() {
    cerr << MOD << endl;
    cerr << h1 << " " << a1 << endl;
    cerr << x1 << " " << y1 << endl;
    cerr << h2 << " " << a2 << endl;
    cerr << x2 << " " << y2 << endl;
}

void stress() {
    for (int tt = 0; ; tt++) {
        cerr << "test id: " << tt << endl;
        MOD = rand() % 100 + 1;
        h1 = rand() % MOD;
        h2 = rand() % MOD;

        a1 = rand() % MOD;
        a2 = rand() % MOD;

        x1 = rand() % MOD;
        x2 = rand() % MOD;
        
        y1 = rand() % MOD;
        y2 = rand() % MOD;
        //printTest();
        int r1 = stupid();
        int r2 = solve();
        if (r1 != -1)
            db2(r1, r2);
        assert(r1 == r2);
    }
}




int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            //cout << stupid() << endl;
            printAns();
            cout << solve() << endl;
        }
    }
    else {
        stress();
    }

    return 0;
}