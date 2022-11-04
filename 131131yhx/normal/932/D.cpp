#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <bitset>
#define M 200010

using namespace std;

typedef long long ll;

ll lans = 0, op, p, q, W[400010], Sm[400010][21];

int Fa[400010][21], cnt = 1;

int main() {
    W[0] = 1e18;
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i <= 20; i++) Sm[0][i] = 1e18;
    for(int i = 1; i <= 20; i++) Sm[1][i] = 1e18;
    while(Q--) {
        scanf("%lld%lld%lld", &op, &p, &q);
        p ^= lans;
        q ^= lans;
        if(op == 1) {
            W[++cnt] = q;
            int nw = p;
            for(int i = 20; i >= 0; i--)
                if(W[Fa[nw][i]] < q) nw = Fa[nw][i];
            nw = Fa[nw][0];
            if(W[p] >= W[cnt]) Fa[cnt][0] = p;
            else Fa[cnt][0] = nw;
            Sm[cnt][0] = W[cnt];
            for(int i = 1; i <= 20; i++)
                Fa[cnt][i] = Fa[Fa[cnt][i - 1]][i - 1];
            for(int i = 1; i <= 20; i++)
                Sm[cnt][i] = min(Sm[cnt][i - 1] + Sm[Fa[cnt][i - 1]][i - 1], (ll) 1e18);
        } else {
            int nw = p;
            lans = 0;
            for(int i = 20; i >= 0; i--)
                if(Sm[nw][i] <= q) {
                    q -= Sm[nw][i];
                    nw = Fa[nw][i];
                    lans += (1 << i);
                }
            printf("%lld\n", lans);
        }
    }
    return 0;
}