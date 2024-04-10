#include <cstdio>
int T, n, k;
int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &k);
        if (k % 3) puts(n % 3 ? "Alice" : "Bob");
        else n %= k + 1, puts(n % 3 || n == k ? "Alice" : "Bob");
    }
}