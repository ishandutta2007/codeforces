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
const ll INF = 1.01e9;
typedef vector<int> vi;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<pair<int,int>> a(n);
    forn(i, n) {
        scanf("%d", &a[i].F);
        a[i].S = i;
    }
    sort(all(a));
    //for (auto x: a) { db2(x.F, x.S); }
    vector<int> used(n);
    vector<vector<int>> answer;
    forn(i, n) {
        if (!used[i]) {
            int x = i;
            vector<int> tmp;
            for (; !used[x]; ) {
                used[x] = 1;
                tmp.pb(x);
                x = a[x].S;
            }
            answer.pb(tmp);
        }
    }
    
    printf("%d\n", sz(answer));
    for (auto x: answer) {
        printf("%d ", sz(x));
        for (auto y: x) 
            printf("%d ", y + 1);
        puts("");
    }
     

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}