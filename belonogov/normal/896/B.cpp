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
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n, -1);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x * 2 <= c) {
            bool done = 0;
            for (int j = 0; j < n && !done; j++) {
                if (a[j] == -1 || a[j] > x) {
                    a[j] = x;
                    cout << j + 1 << endl;
                    done = 1;
                }
            } 
            assert(done);
        }
       else {
            bool done = 0;
            for (int j = n - 1; j >= 0 && !done; j--) {
                if (a[j] == -1 || a[j] < x) {
                    a[j] = x;
                    cout << j + 1 << endl;
                    done = 1;
                }
            } 
            assert(done);
    

        }

        bool ok = a[0] != -1;
        for (int j = 1; j < n; j++) {
            ok &= a[j] != -1 && a[j - 1] <= a[j];
        }
        if (ok) {
            break;
        }
    }
  
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}