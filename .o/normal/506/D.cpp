#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

int N, M;

const int N_ = 100500;
const int M_ = 100500;

typedef unordered_map<int, int> ump;
typedef unordered_set<int> ust;
ump grp[M_];

int get_group (ump &g, int u) {
    if(g[u] == u) return u;
    return g[u] = get_group(g, g[u]);
}

vector<int> same[M_];
int when[M_];
vector<int> ins;

ust large[N_]; int ln;

int Q;
unordered_map<int, int> answer[N_];
pii queries[N_];

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        ump &g = grp[c];
        if(!g.count(a)) g[a] = a;
        if(!g.count(b)) g[b] = b;
        int ag = get_group(g, a);
        int bg = get_group(g, b);
        if(rand() % 2) g[ag] = bg; else g[bg] = ag;
    }
    
    scanf("%d", &Q);
    for(int q = 1; q <= Q; q++) {
        int u, v; scanf("%d%d", &u, &v);
        if(u > v) swap(u, v);
        answer[u][v] = 0;
        queries[q] = pii(u, v);
    }
    
    for(int c = 1; c <= M; c++) {
        ump &g = grp[c];
        ins.clear();
        for(auto it = g.begin(); it != g.end(); it++) {
            int u = it->first, p = get_group(g, it->first);
            if(when[p] != c) {
                same[p].clear();
                ins.push_back(p);
                when[p] = c;
            }
            same[p].push_back(u);
        }
        
        for(int i = 0; i < ins.size(); i++) {
            vector<int>&s = same[ins[i]];
            if((ll)s.size() * s.size() > N) { // large group
                ust &st = large[++ln];
                for(int j = 0; j < s.size(); j++) st.insert(s[j]);
            }else {
                for(int x = 0; x < s.size(); x++) {
                    for(int y = x + 1; y < s.size(); y++) {
                        int a = s[x];
                        int b = s[y];
                        if(a > b) swap(a, b);
                        if(answer[a].count(b)) answer[a][b]++;
                    }
                }
            }
        }
    }
    
    
    for(int q = 1; q <= Q; q++) {
        int u = queries[q].first, v = queries[q].second;// scanf("%d%d", &u, &v);
        int ret = answer[u][v];
        for(int i = 1; i <= ln; i++) {
            if(large[i].count(u) && large[i].count(v)) ++ret;
        }
        printf("%d\n", ret);
    }
    
    return 0;
}