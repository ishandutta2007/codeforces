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
const int N = 2e5 + 10;
const int INF = 1.01e9;
typedef vector<int> vi;
const int M = 30;

struct Node {
    int go[2];
    bool flag;
    Node() {
        memset(go, -1, sizeof go); 
        flag = 0;
    }
};

Node data[N * 30];
int cur = 1;
ll answer = 0;


vector<int> dfs(int v,  int h) {
    vector<int> ret; 
    assert(h >= -1);
    if (h == -1) {
        ret.pb(0);
        return ret;
    }
    //db2(v, h);
    vector<int> r[2];
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        //db(data[v].go[i]);
        if (data[v].go[i] != -1) {
            //db("go");
            r[i] = dfs(data[v].go[i], h - 1);
            cnt++;
        }
    }
    if (cnt == 2) {
        ll mn = INF;
        for (auto x: r[0]) {
            ll curRes = pw(h); 
            int u = data[v].go[1];;
            for (int i = h - 1; i >= 0; i--) {
                int ch = (x >> i) & 1;
                if (data[u].go[ch] != -1) {
                    u = data[u].go[ch];
                }
                else {
                    u = data[u].go[1 - ch];
                    curRes += pw(i);
                }
            }
            mn = min(mn, curRes);
        }
        answer += mn;
    }
    ret = r[0];
    for (auto x: r[1]) {
        ret.pb(x | pw(h));
    }
    return ret;
}


void add(int x) {
    int v = 0;
    for (int i = M - 1; i >= 0; i--) {
        //db(v);
        int ch = (x >> i) & 1;
        if (data[v].go[ch] == -1) {
            data[v].go[ch] = cur++;
        }
        v = data[v].go[ch];
    }
    data[v].flag = 1;
} 

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        add(x);
    }

    //db("DSFSDF");
    dfs(0, M - 1);
    cout << answer << endl;




    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}