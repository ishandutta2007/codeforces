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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
const double pi = acos(-1);

int n, R, V;
double answer;

void read() {
    scanf("%d%d%d", &n, &R, &V);
}

double check(double t) {
    double cir = pi * 2 * R;
    int cnt = t / cir;
    double g = t - cnt * cir;
    return t + 2 * sin(g / R / 2) * R;
}


void solve() {
    //R = 20;
    //double step = 0.01;
    //double mn = 100;
    //for (int i = 0; i < 20000; i++) {
        //assert(check(i * step) < check((i + 1) * step));
        //mn = min(check((i + 1) * step) - check(i * step), mn);
        ////db2(i * step, check(i * step));
    //}
    //db(mn);
    //return;


    for (int i = 0; i < n; i++) {
        int s, f;
        scanf("%d%d", &s, &f);
        double len = f - s;
        double l = max(0.0, len - pi * 5 * R);
        double r = len + pi * 5 * R;
        //db2(l, r);
        //db(check(r));
        for (int it = 0; it < 60; it++) {
            if (check((l + r) / 2) < len)
                l = (l + r) / 2;
            else
                r = (l + r) / 2;
        }
    

        //db(r);
        printf("%.17lf\n", r / V);

    }

}

void printAns() {

}

void stress() {

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
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}