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
const int N = 2e5 + 10;
const int INF = 1e9 + 19;

struct pnt {
    long long x, y;
    pnt () { }
    pnt (long long x, long long y): x(x), y(y) { }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator * (long long k) {
        return pnt(x * k, y * k);
    }
    long long operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    bool operator == (pnt A) {
        return x == A.x && y == A.y; 
    }
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    void Epr() {
        cerr << "x y: " << x << " " << y << endl;
    }
};

vector < pnt > vec; 
pnt p[3][N];
pnt down[3];
pnt b[N];

bool cmpA(pnt a, pnt b) {
    assert(!(a == pnt(0, 0)));
    assert(!(b == pnt(0, 0)));
    int partA = (a.y < 0) || (a.y == 0 && a.x < 0);
    int partB = (b.y < 0) || (b.y == 0 && b.x < 0);
    if (partA != partB) return partA < partB;
    return a * b > 0;
}

void read() {
    for (int t = 0; t < 3; t++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            p[t][i].read();
        
        down[t] = p[t][0];
        for (int i = 0; i < n; i++) {
            vec.pb(pnt(p[t][(i + 1) % n] - p[t][i]));
            if (p[t][i].y < down[t].y || (p[t][i].y == down[t].y && p[t][i].x < down[t].x))
                down[t] = p[t][i];
        }
    }
    sort(vec.begin(), vec.end(), cmpA);
    int cur = 0;
    for (int i = 0; i < (int)vec.size(); ) {
        int j = i;
        pnt sum = pnt(0, 0);
        for (; i < (int)vec.size() && !cmpA(vec[j], vec[i]); i++)
            sum = sum + vec[i];
        vec[cur++] = sum;
    } 
    vec.resize(cur);

    pnt O = down[0] + down[1] + down[2];
    b[0] = O;    
    for (int i = 0; i < (int)vec.size() - 1; i++)
        b[i + 1] = b[i] + vec[i];
    int m;
    scanf("%d", &m);
    int all = vec.size();
    assert(b[0] == b[all - 1] + vec[all - 1]); 

    //for (int i = 0; i < all; i++)
        //b[i].Epr();

    for (int i = 0; i < m; i++) {
        pnt A;
        A.read();
        A = A * 3;
        bool flag = 1;
        flag &= (b[1] - b[0]) * (A - b[0]) >= 0;
        flag &= (A - b[0]) * (b[all - 1] - b[0]) >= 0;
        int l = 1;
        int r = all - 1;
        //db(flag);
        if (flag) {
            while (r - l > 1) {
                if ((A - b[0]) * (b[(l + r) / 2] - b[0]) >= 0)
                    r = (l + r) / 2;
                else
                    l = (l + r) / 2;
            }
            //db2(l, r);
            //(b[r] - b[l]).Epr();
            flag &= (b[r] - b[l]) * (A - b[l]) >= 0;
            //db(flag);
        }
        if (flag)
            puts("YES");
        else
            puts("NO");
    }

}

void solve() {

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