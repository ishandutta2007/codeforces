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


bool check(vector<string> a) {
    int n = a.size();
    int m = a[0].size();
    if (n % 3 != 0) return 0;
    int h = n / 3;
    if (a[0][0] == a[h][0] || a[0][0] == a[h * 2][0] || a[h][0] == a[h * 2][0]) return 0;


    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < h; i++)  {
            for (int j = 0; j < m; j++) {
                if (a[h * t][0] != a[h * t + i][j])
                    return 0;
            }
        }
    }
    return 1;
}


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (check(a)) {
        puts("YES");
    }
    else {
        vector<string> b(m, string(n, ' '));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                b[j][i] = a[i][j];
            }
        if (check(b)) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }




    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}