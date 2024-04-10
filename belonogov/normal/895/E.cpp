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
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
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



vector<dbl> sum;
vector<dbl> updP;
vector<dbl> updM;

void build(int v, int tl, int tr, vector<int>& a) {
    if (tl + 1 == tr) {
        sum[v] = a[tl];
        return;
    }
    build(v * 2 + 1, tl, (tl + tr) / 2, a);
    build(v * 2 + 2, (tl + tr) / 2, tr, a);
    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
}

void push(int v, int tl, int tr) {
    updM[v * 2 + 1] *= updM[v]; 
    updM[v * 2 + 2] *= updM[v]; 
    sum[v * 2 + 1] *= updM[v]; 
    sum[v * 2 + 2] *= updM[v]; 
    updP[v * 2 + 1] *= updM[v]; 
    updP[v * 2 + 2] *= updM[v]; 
    updM[v] = 1;

    updP[v * 2 + 1] += updP[v];
    updP[v * 2 + 2] += updP[v];
    sum[v * 2 + 1] += updP[v] * ((tl + tr) / 2 - tl);
    sum[v * 2 + 2] += updP[v] * (tr - (tl + tr) / 2);
    updP[v] = 0;
}

dbl getSum(int v, int tl, int tr, int l, int r) {
    if (r <= tl || tr <= l) return 0;   
    if (l <= tl && tr <= r) {
        return sum[v];
    }
    push(v, tl, tr);
    return getSum(v * 2 + 1, tl, (tl + tr) / 2, l, r) +
           getSum(v * 2 + 2, (tl + tr) / 2, tr, l, r);
}

void add(int v, int tl, int tr, int l, int r, int type, dbl val) {
    //db2(type, val);
    //db2(tl, tr);
    //db2(l, r);
    if (r <= tl || tr <= l) return;
    if (l <= tl && tr <= r) {
        if (type == 0) {
            updM[v] *= val;                                       
            updP[v] *= val;
            sum[v] *= val;
        }
        else {
            updP[v] += val;
            sum[v] += val * (tr - tl);
        }
        return;
    }
    push(v, tl, tr);
    add(v * 2 + 1, tl, (tl + tr) / 2, l, r, type, val);
    add(v * 2 + 2, (tl + tr) / 2, tr, l, r, type, val);
    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
}


int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, q;
    scanf("%d%d", &n, &q); 
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d",  &a[i]);
    }
    sum.resize(n * 4);
    updP.resize(n * 4);
    updM.resize(n * 4, 1);
    build(0, 0, n, a);
    //add(0, 0, n, 0, 2, 0, 0.5);
    //add(0, 0, n, 0, 2,

    for (int tt = 0; tt < q; tt++) {
        //db(tt);
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int l1, r1, l2, r2;
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2); l1--; l2--;
            int len1 = r1 - l1;
            int len2 = r2 - l2;
            dbl s1 = getSum(0, 0, n, l1, r1);
            dbl s2 = getSum(0, 0, n, l2, r2);
            //db("here");
            //db2(s1, s2);

            add(0, 0, n, l1, r1, 0, (r1 - l1 - 1) * 1.0 / (r1 - l1));
            //db("here");
            add(0, 0, n, l2, r2, 0, (r2 - l2 - 1) * 1.0 / (r2 - l2));
            //db2(getSum(0, 0, n, 0, 2), getSum(0, 0, n, 2, 4));

            add(0, 0, n, l2, r2, 1, s1 / len1 / len2);
            //db2(getSum(0, 0, n, 0, 2), getSum(0, 0, n, 2, 4));
            add(0, 0, n, l1, r1, 1, s2 / len1 / len2);
            //db2(getSum(0, 0, n, 0, 2), getSum(0, 0, n, 2, 4));
            //db(getSum(0, 0, n, 0, n));
            //db(getSum(0, 0, n, 0, 1));
            //db(getSum(0, 0, n, 1, 2));
            //db(getSum(0, 0, n, 2, 3));
            //db(getSum(0, 0, n, 3, 4));

            //db(getSum(0, 0, n, 1, 3));
        }
        else {
            int l, r;
            scanf("%d%d", &l, &r); l--;
            printf("%.17f\n", getSum(0, 0, n, l, r));
        }
    }



    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}