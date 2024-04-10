#include <cstdio>
int T, n, x;
int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &x);
        printf("%d\n", x << 1);
    }
}