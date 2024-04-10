#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)          (a).begin(), (a).end()
#define sz(a)           int((a).size())
#define FOR(i, a, b)    for (int i(a); i < b; ++i)
#define REP(i, n)       FOR(i, 0, n)
#define UN(v)           sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)        memset(a, b, sizeof a)
#define pb              push_back
#define X               first
#define Y               second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int mod = 1000000009;

inline int add(int x, int y) { return (x += y) < mod ? x : x - mod; }

int n, m;
map<string, int> FF;
vector<string> U;
string s[11];

int id(const string &s) {
    auto i = FF.find(s);
    if (i != FF.end())
        return i->Y;
    FF[s] = sz(U);
    U.pb(s);
    return sz(U) - 1;
}

int fid(const string &s) {
    auto i = FF.find(s);
    return i == FF.end() ? -1 : i->Y;
}

int F[111][4];
int finish[111];

int G[1111][111][15];

int g(int i, int s, int k) {
    if (k > 13) return 0;
    if (i == n) return k == 0;
    int &res = G[i][s][k];
    if (res < 0) {
        res = 0;
        ++k;
        REP (j, 4) if (~F[s][j]) {
            int w = finish[F[s][j]];
            res = add(res, g(i + 1, F[s][j], w >= k ? 0 : k));
        }
    }
    return res;
}

int main(){
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    freopen("x.out", "w", stdout);
    #endif
    cin >> n >> m;
    id("");
    CL(F, -1);
    REP (i, m) {
        cin >> s[i];
        REP (j, sz(s[i])) 
            id(s[i].substr(0, j + 1));
        finish[id(s[i])] = sz(s[i]);
    }
    for (auto w : U) {
        int x = id(w);
        REP (k, 4) {
            string z = w + ("ACGT"[k]);
            for (; sz(z); z.erase(0, 1)) {
                int y = fid(z);
                if (~y) {
                    F[x][k] = y;
                    break;
                }
            }
        }
        for (; sz(w); w.erase(0, 1)) {
            int y = fid(w);
            if ((~y) && finish[y] > 0) {
                finish[x] = finish[y];
                break;
            }
        }
    }
    CL(G, -1);
    cout << g(0, 0, 0) << endl;
    return 0;
}