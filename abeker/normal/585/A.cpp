#include <cstdio>
#include <deque>
using namespace std;

typedef long long ll;

const int MAXN = 4005;

int N;
int v[MAXN], d[MAXN], p[MAXN];
deque <int> V, sol;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d%d", v + i, d + i, p + i);
}

void solve() {
    for (int i = 0; i < N; i++) 
        V.push_back(i);
    
    while (!V.empty()) {
        int tmp = V.front();
        V.pop_front();
        sol.push_back(tmp);
        for (int i = 0; i < v[tmp] && i < V.size(); i++)
            p[V[i]] -= v[tmp] - i;
        
        deque <int> nxt;
        ll tot = 0;
        for (int i = 0; i < V.size(); i++) 
            if (p[V[i]] < tot) 
                tot += (ll)d[V[i]];
            else {
                nxt.push_back(V[i]);
                p[V[i]] -= (int)tot;
            }
        
        V = nxt;
    }
    
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d ", ++sol[i]);
    puts("");
}

int main() {
    load();
    solve();    
    return 0;
}