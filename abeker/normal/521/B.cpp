#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;
const int MOD = 1000000009;

int N;
int x[MAXN], y[MAXN];
map <pii, int> cubes;
vector <int> par[MAXN], ch[MAXN];
set <int> S;

inline int mul(int x, int y) {
    return (ll)x * y % MOD;
}

inline int add(int x, int y) {
    return (x + y) % MOD;
}

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", x + i, y + i);
}

void out(int x) {
    if (par[x].size() == 1 && S.count(par[x][0]))
        S.erase(par[x][0]);
}

void remove_par(int c, int p) {
    vector <int> v;
    for (int i = 0; i < par[c].size(); i++) 
        if (par[c][i] != p) v.push_back(par[c][i]);
    par[c] = v;
    out(c);
}

void remove_ch(int p, int c) {
    vector <int> v;
    for (int i = 0; i < ch[p].size(); i++) 
        if (ch[p][i] != c) v.push_back(ch[p][i]);
    ch[p] = v;
}

int solve() {
    for (int i = 0; i < N; i++) 
        cubes[pii(x[i], y[i])] = i + 1;
    
    for (int i = 0; i < N; i++) 
        for (int j = -1; j < 2; j++) {
            int idx = cubes[pii(x[i] + j, y[i] - 1)];
            if (!idx) continue; idx--;
            par[i].push_back(idx);
            ch[idx].push_back(i);
        }
    
    for (int i = 0; i < N; i++)
        S.insert(i);
        
    for (int i = 0; i < N; i++)
        out(i);
    
    int sol = 0;
    for (int i = 0; i < N; i++) {
        int curr = -1;
        if (i & 1) curr = *S.begin();
        else curr = *(--S.end());
        S.erase(curr);
        sol = add(mul(sol, N), curr);
        for (int j = 0; j < ch[curr].size(); j++) 
            remove_par(ch[curr][j], curr);
        for (int j = 0; j < par[curr].size(); j++) 
            remove_ch(par[curr][j], curr);
        if (par[curr].size() == 1) {
            int p = par[curr][0];
            S.insert(p);
            for (int j = 0; j < ch[p].size(); j++) 
                out(ch[p][j]);
        }
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}