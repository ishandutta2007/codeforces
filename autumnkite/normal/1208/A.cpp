#include <cstdio>
int T, a, b, n;
int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &a, &b, &n);
        if (n % 3 == 0) printf("%d\n", a);
        else if (n % 3 == 1) printf("%d\n", b);
        else printf("%d\n", a ^ b);
    }
}