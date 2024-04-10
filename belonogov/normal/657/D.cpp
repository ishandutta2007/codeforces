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
const int N = 2e5;
const long long INF = 1e9 + 19;
const int T = 60;

struct Prob {
    long long p, t;
    int id;
    bool operator == (Prob other) {
        return t * other.p == other.t * p;
    }
};


int n;
Prob b[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%lld", &b[i].p);
    for (int i = 0; i < n; i++)
        scanf("%lld", &b[i].t);
}

bool cmpP(Prob A, Prob B) {
    if (A == B) {
        return A.p < B.p;
    }
    return A.t * B.p < B.t * A.p;
}

long long sumT = 0; 

double mn[N];
double mx[N];
long long pp[N];

bool check(double c) {
    long long tmr = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        long long st = tmr;
        for (; i < n && b[j] == b[i]; i++)
            st += b[i].t;
             
        for (; j < i; j++) {
            mn[b[j].id] = b[j].p * (1 - c * st / sumT);        
            mx[b[j].id] = b[j].p * (1 - c * (tmr + b[j].t) / sumT);
        }
        tmr = st;
    }  
    double prefMax = -1;


    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && pp[j] == pp[i]; i++)
            if (mn[i] < prefMax) 
                return 0;
        for (; j < i; j++)
            prefMax = max(prefMax, mx[j]);

    }
    return 1;
}

bool cmpPP(Prob A, Prob B) {
    return A.p < B.p;
}

void solve() {
    sort(b, b + n, cmpPP);
    for (int i = 0; i < n; i++) {
        b[i].id = i;
        pp[i] = b[i].p;
    }





    for (int i = 0; i < n; i++)
        sumT += b[i].t;
    sort(b, b + n, cmpP);
    
    //for (int i = 0; i < n; i++)
        //cerr << b[i].p << " " << b[i].t << " " << b[i].id << endl;
    //db(check(0.01));
    //for (int i = 0; i < n; i++)
        //db2(mn[i], mx[i]);
    //return;

    double l = 0;
    double r = 1;
    for (int it = 0; it < T; it++) {
        if (check((l + r) / 2))
            l = (l + r) / 2;
        else
            r = (l + r) / 2;
    }

    printf("%.17f\n", l);
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
        }
    }
    else {
        stress();
    }

    return 0;
}