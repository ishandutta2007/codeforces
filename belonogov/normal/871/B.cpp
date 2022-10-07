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


int ask(int v, int u) {
    cout << "? " << v  << " " << u << endl;
    int res;
    cin >> res;
    return res;
}


int main(){
//#ifdef HOME 
    //assert(freopen("in", "r", stdin));
//#endif
    int n;
    cin >> n;
    int ab0 = ask(0, 0);
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 1; i < n; i++) {
        a[i] = ask(0, i);
        b[i] = ask(i, 0);
    }

    vector<int> ex;
    int answer = 0;
    vector<int> p(n);
    vector<int> rev(n);
    for (int z = 0; z < n; z++) {
        p[0] = z;
        rev[0] = ab0 ^ z;
        for (int i = 1; i < n; i++) {
            p[i] = b[i] ^ rev[0];
            rev[i] = a[i] ^ p[0];
        }
        bool fail = 0;
        for (int i = 0; i < n; i++) {
            fail |= rev[i] >= n;
            fail |= p[i] >= n; 
        }
        if (!fail) {
            //dbv(p);
            //dbv(rev);
            //cerr << endl;
            bool ok = 1;
            for (int i = 0; i < n; i++) {
                ok &= rev[p[i]] == i;
            }
            if (ok) {
                ex = p;
                answer++;
            }
        }
    }
    cout << "!" << "\n";
    cout << answer << "\n";
    for (auto x: ex) {
        cout << x << " ";
    }
    cout << endl;






    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}