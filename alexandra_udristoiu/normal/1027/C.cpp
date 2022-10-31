#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int t, n, i, nr, sol1, sol2;
int a, b, sola, solb;
int v[1000005], w[1000005], ff[10005];
int main(){
    scanf("%d", &t);
    for(; t; t--){
         scanf("%d", &n);
        for(i = 1; i <= n; i++){
            scanf("%d", &w[i]);
        }
        sola = 1000000000;
        solb = 1;
        nr = 0;
        sort(w + 1, w + n + 1);
        for(i = 2; i <= n; i++){
           if(w[i] == w[i - 1]){
                v[++nr] = w[i];
                i++;
           }
        }
        for(i = 2; i <= nr; i++){
            a = 4 * (v[i] + v[i - 1]) * (v[i] + v[i - 1]);
            b = v[i] * v[i - 1];
            if(a * 1LL * solb < b * 1LL * sola){
                sola = a;
                solb = b;
                sol1 = v[i];
                sol2 = v[i - 1];
            }
        }
        printf("%d %d %d %d\n", sol1, sol1, sol2, sol2);
    }
}