#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, X[200010], Y[200010], Nw[200010], nwans = 0, ans = 2333333, res;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &Y[i]);
    for(int i = 1; i <= m; i++) if(Y[i]) res++;
    int t = 1;
    for(int i = 1; i <= n; i++) {
        if(Nw[X[i]] >= Y[X[i]]) nwans++, Nw[X[i]]++;
        else if(Nw[X[i]] < Y[X[i]] - 1) Nw[X[i]]++;
        else if(!--res) {
            Nw[X[i]]++;
            while(!res) {
                ans = min(ans, nwans);
                if(Nw[X[t]] > Y[X[t]]) nwans--, Nw[X[t]]--;
                else res++, Nw[X[t]]--;
                t++;
            }
        } else Nw[X[i]]++;
    }
    printf("%d\n", ans == 2333333 ? -1 : ans);
    return 0;
}