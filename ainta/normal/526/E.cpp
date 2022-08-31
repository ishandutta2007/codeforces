#include<stdio.h>
#include<algorithm>
using namespace std;
int n, nxt[1010000], C[1010000], P[1010000], Q;
long long S[2010000], K;
void Do(){
    int Res;
    if (K >= S[n]){
        printf("1\n");
        return;
    }
    int i, pv = 0;
    for (i = 1; i <= 2 * n; i++){
        while (pv <= n && S[i] - S[pv] > K){
            nxt[pv] = i - 1;
            pv++;
        }
    }
    for (i = n - 1; i >= 0; i--){
        if (nxt[i] >= n){
            C[i] = 1, P[i] = nxt[i];
            continue;
        }
        C[i] = C[nxt[i]] + 1, P[i] = P[nxt[i]];
    }
    Res = C[0];
    for (i = 1; i <= nxt[0]; i++){
        if (P[i] < i + n){
            Res = min(Res, C[i] + 1);
        }
        else{
            Res = min(Res, C[i]);
        }
    }
    printf("%d\n", Res);
}
int main(){
    int i, a;
    scanf("%d%d", &n, &Q);
    for (i = 1; i <= n; i++){
        scanf("%d", &a);
        S[i] = S[i - 1] + a;
    }
    for (i = 1; i <= n; i++)S[i + n] = S[i] + S[n];
    while (Q--){
        scanf("%lld", &K);
        Do();
    }
}