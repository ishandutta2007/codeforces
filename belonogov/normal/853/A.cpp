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
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> c(n);
    forn(i, n) {
        scanf("%d", &c[i]);
    }
    ll answer = 0;
    vector<int> perm(n); 
    set<pair<int,int>> q;
    ll sum = 0;
    forn(i, k) {
        q.insert({c[i], i});
        sum += c[i];
        answer += sum;
    }
    forn(i, n) {
        if (i + k < n) {
            q.insert({c[i + k], i + k});
            sum += c[i + k];
        }
        auto x = *q.rbegin();
        sum -= x.F;
        answer += sum;
        perm[x.S] = i + k;
        q.erase(x);
    }
    printf("%lld\n", answer);
    forn(i, n) {
        printf("%d ", perm[i] + 1);
    }
    cout << endl;

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}