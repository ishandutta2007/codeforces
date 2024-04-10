#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

#define SIT set <int>::iterator

using namespace std;

set <int> S[200010];

bool cant[200010];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        S[x].insert(y);
        S[y].insert(x);
    }
    for(int i = 1; i <= n; i++) if(S[i].size() == 1) {
        int tmp = i, nx = *S[tmp].begin();
        while(S[nx].size() == 2) {
            S[nx].erase(tmp);
            tmp = nx;
            nx = *S[tmp].begin();
        }
    }
    vector <int> V;
    V.clear();
    for(int i = 1; i <= n; i++) if(S[i].size() == 3) {
        int tmp = 0;
        for(SIT it = S[i].begin(); it != S[i].end(); it++) tmp += S[*it].size() == 1;
        if(tmp == 2) V.push_back(i), cant[i] = 1;
    }
    for(int i = 0; i < V.size(); i++)
        for(SIT it = S[V[i]].begin(); it != S[V[i]].end(); it++)
            if(S[*it].size() != 1 || cant[*it]) {
                S[V[i]].clear();
                S[V[i]].insert(*it);
                break;
            }
    for(int i = 1; i <= n; i++) {
        int tmp = 0;
        for(SIT it = S[i].begin(); it != S[i].end(); it++) tmp += S[*it].size() != 1;
        if(tmp >= 3) return puts("No"), 0;
    }
    puts("Yes");
    return 0;
}