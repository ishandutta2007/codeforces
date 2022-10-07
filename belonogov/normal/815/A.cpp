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
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    auto b = a;

    int mn = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mn = min(mn, a[i][j]);

    vector<int> row(n);
    vector<int> col(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] -= mn;
    if (n < m) {
        for (int i = 0; i < n; i++)
            row[i] += mn;
    }
    else {
        for (int i = 0; i < m; i++)
            col[i] += mn;
    }

    int x = -1, y = -1;
    forn(i, n)
        forn(j, m)
            if (a[i][j] == 0) {
                x = i;
                y = j;
            }
    //db("done");

    assert(x != -1);
    forn(i, n) 
        row[i] += a[i][y];
    forn(i, m)
        col[i] += a[x][i];

    bool ok = 1;
    forn(i, n) forn(j, m)
        ok &= row[i] + col[j] == b[i][j];

    if (ok) {
        int sum = 0;
        for (auto xx: row) sum += xx;
        for (auto xx: col) sum += xx;
        printf("%d\n", sum);
        forn(i, n) 
            forn(t, row[i])
                cout << "row " << i + 1 << "\n";
        forn(i, m) 
            forn(t, col[i])
                cout << "col " << i + 1 << "\n";

    }
    else {
        puts("-1");
    }
    

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}