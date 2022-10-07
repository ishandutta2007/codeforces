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



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    

    //for (;;) {
    int T = 1001;
    vector<int> used(T);
    vector<int> a;
    //int tmr = 0;
    //int cntFail = 0;
    bool win = 0;
    vector<int> perm;
    for (int i = 1; i <= 500; i++) {
        perm.pb(i);
    }
    random_shuffle(all(perm));
    int mxLen = 0;
    vector<int> c;
    function<void(int)> rec = [&](int pos) {
        if (win) return;
        if (pos > mxLen) {
            mxLen = pos;
            //db(mxLen);
        }
        if (pos == n) {
            win = 1;
            c = a;
            return;
        }
        for (auto x: perm) {
            bool ok = 1;
            for (auto y: a) {
                ok &= used[x + y] == 0;
                ok &= x != y;
            }
            if (ok) {
                for (auto y: a) 
                    used[x + y] = 1;

                a.pb(x);
                rec(pos + 1);
                a.pop_back();
                for (auto y: a) 
                    used[x + y] = 0;
            }
        }

    };


    rec(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << 0 << " ";
            }
            else {
                cout << c[i] + c[j] << " ";
            }
        }
        cout << endl;
    }

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}