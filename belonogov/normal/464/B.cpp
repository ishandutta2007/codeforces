#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = -1;
const int INF = 1e9;
const int n = 8;
const int fac = 6;

struct pnt {
    long long x, y, z;
    pnt() { } 
    pnt(long long x, long long y, long long z): x(x), y(y), z(z) { }
    long long operator % (pnt A) {
        return x * A.x + y * A.y + z * A.z;
    }
    void nextPerm() {
        int a[3];
        a[0] = x;
        a[1] = y;
        a[2] = z;
        next_permutation(a, a + 3);
        x = a[0];
        y = a[1];
        z = a[2];
    }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y, z - A.z);
    }
    long long len() {
        return x * x + y * y + z * z;
    }
    void print() {
        printf("%lld %lld %lld\n", x, y, z);
    }
};

pnt p[n];
pnt b[n];
int id[n];
bool use[n];


void read() {
    srand(1919);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld\n", &p[i].x, &p[i].y, &p[i].z);
    } 
}

bool checkDist(int k, long long r) {
    for (int i = 0; i < k - 1; i++) {
        int x = __builtin_popcount((k - 1) ^ i);
        if ((b[i] - b[k - 1]).len() != x * r)
            return 0;
    }
    return 1;
}
int cnt = 0;

bool cmp(pair < int, pnt > a, pair < int, pnt > b) {
    return a.fr < b.fr;
}

void gen(int k, long long r) {
    //cnt++;
    if (k == n) {
        printf("YES\n");
        vector < pair < int, pnt > > t;
        for (int i = 0; i < n; i++)
            t.pb(mp(id[i], b[i]));
        sort(t.begin(), t.end(), cmp);
        for (int i = 0; i < n; i++)
            t[i].sc.print();
        exit(0);
    }
    for (int i = 0; i < n; i++)
        if (!use[i])  {
            pnt A = p[i];
            for (int j = 0; j < fac; j++) {
                b[k] = A; 
                id[k] = i;
                long long r1 = (r == -1)? (A - b[0]).len(): r;
                if (r1 != 0 && checkDist(k + 1, r1)) {
                    use[i] = 1;
                    gen(k + 1, r1);
                    use[i] = 0;
                }
                A.nextPerm();
            } 
        }
}

void solve() {
    use[0] = 1;
    b[0] = p[0];
    gen(1, -1);
}

void printAns() {
    printf("NO\n");
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}