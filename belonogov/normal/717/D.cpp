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
const int BASE = 7;
const int SZ = pw(BASE);


vector<double> mul(vector<double> a, vector<double> b) {
    vector<double> res(SZ);
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++)
            res[i ^ j] += a[i] * b[j];
    return res;
}

vector<double> binPow(int b, vector<double> a) {
    vector<double> res(SZ);
    res[0] = 1;
    for (; b > 0; b /= 2) {
        if (b % 2)
            res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, x;
    vector<double> a(SZ);
    scanf("%d%d", &n, &x);
    for (int i = 0; i <= x; i++)
        scanf("%lf", &a[i]);

    auto res = binPow(n, a);
    printf("%.17f\n", 1 - res[0]);
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}