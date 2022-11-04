#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define M 400010

using namespace std;

int n, Nxt[M][26], Pr[M], H[M], D[M], K[M], Cnt = 0, l = 0;

char ch[M], S[M];

void add(int x, int b) {
    H[++Cnt] = H[l] + 1;
    K[Cnt] = b;
    while(l != -1 && !Nxt[l][x]) {
        Nxt[l][x] = Cnt;
        l = Pr[l];
    }
    if(l == -1) l = Cnt; else {
        int c = Nxt[l][x];
        if(H[c] == H[l] + 1) Pr[l = Cnt] = c; else {
            memcpy(Nxt[++Cnt], Nxt[c], sizeof Nxt[c]);
            H[Cnt] = H[l] + 1;
            Pr[Cnt] = Pr[c];
            Pr[Cnt - 1] = (Pr[c] = Cnt);
            while(l != -1 && Nxt[l][x] == c) {
                Nxt[l][x] = Cnt;
                l = Pr[l];
            }
            l = Cnt - 1;
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s%s", ch + 1, S + 1);
    Pr[0] = -1;
    for(int i = 1; i <= n; i++) add(ch[i] - 'a', '1' - S[i]);
    vector <int> V;
    V.clear();
    for(int i = 1; i <= Cnt; i++) D[Pr[i]]++;
    for(int i = 1; i <= Cnt; i++) if(!D[i]) V.push_back(i);
    for(int i = 0; i < V.size(); i++) {
        K[Pr[V[i]]] += K[V[i]];
        if(!--D[Pr[V[i]]]) V.push_back(Pr[V[i]]);
    }
    long long ans = 0;
    for(int i = 1; i <= Cnt; i++) ans = max(ans, (long long) H[i] * K[i]);
    printf("%lld\n", ans);
    return 0;
}