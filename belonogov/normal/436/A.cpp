#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = -1;
const int INF = 1e9;

vector < pair < int, int > > b[2];
int ans = 0, x;

void solve(int f) {
    vector < bool > use[2];
    use[0].assign(b[0].size(), 0);
    use[1].assign(b[1].size(), 0);
    int i;
    int jump = x;
    for (i = 0; ; i++) {
        int t = f ^ (i % 2); 
        int cur = -1;
        for (int j = 0; j < (int)b[t].size(); j++)
            if (!use[t][j] && b[t][j].fr <= jump && (cur == -1 || b[t][cur].sc < b[t][j].sc)) {
                cur = j;
            }
        if (cur == -1) {
            ans = max(ans, i);
            break;
        }
        jump += b[t][cur].sc;
        use[t][cur] = 1;
    }
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, t, h, m;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &t, &h, &m);
        b[t].pb(mp(h, m));
    }
    solve(0);
    solve(1);
    printf("%d\n", ans);
    return 0;
}