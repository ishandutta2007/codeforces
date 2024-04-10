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
const int ALF = 26;



void ret() {
    puts("NO");
    exit(0);
}
int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<int> nxt(ALF, -1);
    bool fail = 0;
    vector<int> canFirst(ALF, 1);
    vector<int> used(ALF);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto ch: s) {
            used[ch - 'a'] = 1;
        }
        for (int j = 0; j + 1 < sz(s); j++) {
            int v = s[j] - 'a';
            int u = s[j + 1] - 'a';
            if (nxt[v] != -1 && nxt[v] != u) {
                fail = 1;
            }
            nxt[v] = u;
            canFirst[u] = 0;
        }
    }
    if (fail) {
        ret();
    }
    //db("tut");
    
    vector<string> res;
    vector<int> vis(ALF);
    for (int i = 0; i < ALF; i++) {
        if (used[i] && canFirst[i]) {
            //db(i);
            string tmp;
            int v = i;
            for (;v != -1;) {
                if (vis[v]) {
                    ret();
                }
                vis[v] = 1;
                tmp.pb('a' + v);
                v = nxt[v];
            }
            res.pb(tmp);
        }
    }

    for (int i = 0; i < ALF; i++) {
        if (used[i] && !vis[i]) {
            ret();
        }
    }

    sort(all(res));
    for (auto x: res) {
        cout << x;
    }
    cout << endl;

   
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}