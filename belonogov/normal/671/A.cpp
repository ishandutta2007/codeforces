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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;

struct pnt {
    double x, y;
    pnt () { }
    pnt (double x, double y): x(x), y(y) { }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    void read() {
        scanf("%lf%lf", &x, &y);
    }
};

pnt A, B, O;
pnt p[N];
int n;


void read() {
    A.read();
    B.read();
    O.read();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i].read();
    }
}

void solve() {
    double sum = 0;
    //db(n);
    for (int i = 0; i < n; i++)
        sum += (p[i] - O).len();
    //db(sum);
    vector < pair < double, int > > idA, idB; 
    for (int i = 0; i < n; i++) {
        idA.pb(mp(-(p[i] - O).len() + (p[i] - A).len(), i));
        idB.pb(mp(-(p[i] - O).len() + (p[i] - B).len(), i));
    }
    idA.pb(mp(0, -1));
    idB.pb(mp(0, -1));
    
    sort(idA.begin(), idA.end());
    sort(idB.begin(), idB.end());

    //for(auto x: idA)
        //db2(x.fr, x.sc);
    //cerr << endl;
    //for(auto x: idB)
        //db2(x.fr, x.sc);

    double mn = INF * 1ll * 10;
    for (int i = 0; i < min(2, (int)idA.size()); i++)
        for (int j = 0; j < min(2, (int)idB.size()); j++) {
            if (idA[i].sc == idB[j].sc) continue;
            mn = min(mn, idA[i].fr + idB[j].fr); 
        }
    printf("%.17f\n", sum * 2 + mn);
}

void stress() {

}


int main(){
#ifdef MY_DEBUG
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