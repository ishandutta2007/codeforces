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



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<int> s(n), g(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &s[i], &g[i]);
    }
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    l[0] = 0;
    r[0] = INF;
    bool fail = 0;
    for (int i = 0; i < n; i++) {
        l[i + 1] = max(s[i], l[i] - 1);
        r[i + 1] = min(s[i] + g[i], r[i] + 1);
        if (l[i + 1] > r[i + 1])
            fail = 1;
    }
    if (fail) {
        puts("-1");
        return 0;
    }
    int x = r[n];
    ll answer = 0;
    vector<int> s2(n);
    for (int i = n - 1; i >= 0; i--) {
        //db3(s[i], x, s[i] + g[i]);
        assert(s[i] <= x && x <= s[i] + g[i]);
        s2[i] = x;
        answer += x - s[i]; 
        int newX = x + 1;
        newX = min(newX, r[i]);
        assert(abs(newX - x) <= 1);
        x = newX;
    }

    cout << answer << endl;
    for (auto y: s2) {
        cout << y << " ";
    }
    cout << endl;



    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}