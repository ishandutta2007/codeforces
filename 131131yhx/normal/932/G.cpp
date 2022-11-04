#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 1000010
#define P 1000000007

using namespace std;

typedef long long ll;

char ch[M], Ch[M];

int n;

ll F[M], S[M];

int C[M][26], Pr[M], Sz[M], D[M], Pl[M], cnt = 1, l = 1, tot = 0;

int getp(int x) {
    for(; Ch[tot - Sz[x] - 1] != Ch[tot]; x = Pr[x]);
    return x;
}

void add(int x, int b) {
    Ch[++tot] = x;
    l = getp(l);
    if(C[l][x]) l = C[l][x]; else {
        Sz[++cnt] = Sz[l] + 2;
        Pr[cnt] = C[getp(Pr[l])][x];
        l = (C[l][x] = cnt);
        D[l] = Sz[l] - Sz[Pr[l]];
    }
    for(int i = l; i; i = Pl[i]) {
        if(D[i] == D[Pr[i]]) {
            Pl[i] = Pl[Pr[i]];
            S[i] = (F[tot - Sz[Pl[i]] - D[i]] + S[Pr[i]]) % P;
        } else {
            Pl[i] = Pr[i];
            S[i] = F[tot - Sz[Pl[i]] - D[i]];
        }
        if(b) F[tot] = (F[tot] + S[i]) % P;
    }
}

int main() {
    Ch[0] = 123;
    scanf("%s", ch);
    n = strlen(ch);
    Pr[0] = 1;
    Sz[1] = -1;
    F[0] = 1;
    for(int i = 0; i < n / 2; i++) {
        add(ch[i] - 'a', 0);
        add(ch[n - i - 1] - 'a', 1);
    }
    printf("%lld\n", (F[n] % P + P) % P);
    return 0;
}