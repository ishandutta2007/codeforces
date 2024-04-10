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



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m, Q;
    scanf("%d%d%d", &n, &m, &Q);
    ll sumA = 0;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        sumA += x * ((i % 2 == 0)? 1 : -1);
    }
    vector<int> b(m);
    forn(i, m) {
        scanf("%d", &b[i]);
    }
    set<ll> q;
    ll curSum = 0;
    forn(i, n) {
        curSum += b[i] * (i % 2 == 0? -1: 1);
    }

    for (int i = n; i <= m; i++) {
        q.insert(curSum);
        if (i < m) {
            curSum += b[i - n];
            curSum *= -1;
            curSum += b[i] * (n % 2 == 0? 1: -1);
        }
    }
     

    
    auto get = [&](ll curA) {
        auto it = q.lower_bound(-curA);   
        ll answer = 1e18;
        if (it != q.end()) {
            answer = min(answer, abs(curA + *it));
        }
        if (it != q.begin()) {
            it--;
            answer = min(answer, abs(curA + *it));
        }
        return answer;
    };
    

    printf("%lld\n", get(sumA));
    for (int i = 0; i < Q; i++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x); l--; 
        if ((r - l) % 2 == 1) {
            if (l % 2 == 0) {
                sumA += x;
            }
            else {
                sumA -= x;
            }
        }
        printf("%lld\n", get(sumA));
    }






    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}