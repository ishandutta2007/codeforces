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
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int> (m));
    int cur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = cur++;
        }
    }
    set<pair<int,int>> block;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            block.insert({a[i][j], a[i + 1][j]});
            block.insert({a[i + 1][j], a[i][j]});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            block.insert({a[i][j], a[i][j + 1]});
            block.insert({a[i][j + 1], a[i][j]});
        }
    }
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                even.pb(a[i][j]);
            }
            else {
                odd.pb(a[i][j]);
            }
        }
    }
    mt19937 rnd;

    auto shuffle = [&](vector<int>& id) {
        for (int i = 0; i < sz(id); i++) {
            int p = rnd() % (i * 1ll + 1);
            swap(id[i], id[p]);
        }
    };

    vector<int> tmp;
    for (;;) {
        if (clock() * 1.0 / CLOCKS_PER_SEC > 1.5) {
            puts("NO"); 
            return 0;
        }
        tmp.clear();
        if (rand() % 2 == 0) {
            shuffle(odd);
            shuffle(even);
            tmp.insert(tmp.end(), all(odd));
            tmp.insert(tmp.end(), all(even));
        }
        else {
            for (int i = 0; i < n * m; i++) {
                tmp.pb(i);
            }
            shuffle(tmp);
        }
        bool ok = 1;
        int cc = 0;
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = tmp[cc++];
            }
        } 
         

       for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                ok &= block.count({b[i][j], b[i + 1][j]}) == 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                ok &= block.count({b[i][j], b[i][j + 1]}) == 0;
            }
        }

        if (ok) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++, cout << "\n") {
                for (int j = 0; j < m; j++) {
                    cout << b[i][j] + 1 << " ";
                }
            }
            return 0;
            //break;
        }
        else {
            //db("fail");
        }

    }




    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}