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
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef double dbl;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, p;
    scanf("%d%d", &n, &p);
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d",  &a[i].F, &a[i].S);
    }
    sort(all(a), [](pair<int,int> A, pair<int,int> B) {
            return A.S * 1ll * B.F < B.S * 1ll * A.F;
            });


    bool flag = 0;
    ll sumA = 0;
    ll sumB = 0;
    double tmp = 1e10;
    for (int i = 0; i < n; i++) {
        sumA += a[i].F;
        sumB += a[i].S;
        if (sumA > p) {
            tmp = min(tmp, sumB * 1.0 / (sumA - p));
            flag = 1;
        } 
    }
    if (flag == 0)
        puts("-1");
    else
        printf("%.17f\n", tmp);

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}