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

struct pt {
    int x, y, id, t;
    int st() const {
        return x + y - t;
    }
    int cp() const {
        return x - y;
    }
};


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif  
    int n, w, h;
    scanf("%d%d%d", &n, &w, &h);
    vector<pt> a;
    forn(i, n) {
        int type, p, t;
        scanf("%d%d%d", &type, &p, &t);
        if (type == 1) {
            a.pb({p, 0, i, t});
        }
        else {
            a.pb({0, p, i, t});
        }
    }
    sort(all(a), [](pt A, pt B) {
            return A.st() < B.st();
            });

    vector<int> ax(n);
    vector<int> ay(n);
    //for (auto p: a) {
        //db(p.st());
    //}

    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && a[j].st() == a[i].st(); i++);
        //db2(j, i);
        vector<pt> fin;
        for (int t = j; t < i; t++) {
            if (a[t].x == 0) {
                fin.pb({w, a[t].y, 0, 0});
            }
            else {
                fin.pb({a[t].x, h, 0, 0});
            }
        }
        sort(all(fin), [](pt A, pt B) {
                return A.cp() < B.cp();
                });

        vector<pt> b(a.begin() + j, a.begin() + i); 
        sort(all(b), [](pt A, pt B) {
                return A.cp() < B.cp();
                });
        //db2(b.size(), fin.size());
        forn(t, sz(b)) {
            //db(b[t].id);
            ax[b[t].id] = fin[t].x;
            ay[b[t].id] = fin[t].y;
        }



    }
    db(ax.size());

    forn(i, n) {
        printf("%d %d\n", ax[i], ay[i]);
    }
        
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}