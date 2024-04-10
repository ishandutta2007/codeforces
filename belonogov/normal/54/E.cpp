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
const int N = 1e5;
const long long INF = 1e15 + 19;

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
    pnt() { }
    pnt(double x, double y): x(x), y(y) { }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    double operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    double operator % (pnt A) {
        return x * A.x + y * A.y;
    }
    pnt operator / (double k) {
        return pnt(x / k, y / k);
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    pnt norm() {
        return (*this) / len();
    }
    void read(){
        scanf("%lf%lf", &x, &y);
    }
    void Epr() {
        cerr << "x y: " << x << " " << y << endl;
    }
};

pnt p[N];
int n;
double answer = INF;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        p[i].read();
}

void solve1() {
    //db("here!");
    //for (int i = 0; i < n; i++)
        //p[i].Epr();

    int cur = 1; 
    double inner = 0;
    for (int i = 0; i < n; i++) {
        pnt v = (p[i] - p[(i + n - 1) % n]).norm();
        //db2(i, inner);
        for (;;) {
            pnt u = p[(cur + 1) % n] - p[cur % n];
            if (v % u > 0) {
                double delta = (p[cur] - p[i]) * (p[(cur + 1) % n] - p[i]);
                assert(lessE(0, delta));
                inner += delta;
                cur = (cur + 1) % n;
            }
            else
                break;
        } 
        //db2(i, cur);
        double area = (v % (p[cur] - p[i])) * (v * (p[cur] - p[i]));

        double delta = (p[(i + 1) % n] - p[i]) * (p[cur] - p[i]);
        assert(lessE(0, delta));
        //db2(area, inner);

        if (area < 0)  {
            answer = 0;
            db("zero");
        }
        else 
            answer = min(answer, area - inner);

        inner -= delta;
    }
}

void solve() {
    double area = 0;
    for (int i = 0; i < n; i++)
        area += (p[i] * p[(i + 1) % n]);
    if (area < 0) 
        reverse(p, p + n);
    solve1(); 
    for (int i = 0; i < n; i++)
        p[i].x *= -1;
    reverse(p, p + n);
    solve1();
    printf("%.17f\n", answer / 2); 
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "w", stdout);
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