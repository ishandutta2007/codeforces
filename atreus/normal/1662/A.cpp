#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 77;
int n , b[N] , d[N] , f[100];
void test() {
    memset(f , 0 , sizeof f);
    scanf("%d" , & n);
    for(int i = 1;i <= n;++ i) {
        scanf("%d %d" , b + i , d + i);
        f[d[i]] = max(f[d[i]] , b[i]);
    }
    int sum = 0;
    for(int i = 1;i <= 10;++ i) {
        sum += f[i];
        if(f[i] == 0) {
            printf("MOREPROBLEMS\n");
            return ;
        }
    }
    printf("%d\n" , sum);
}
int main() {
    int tst;
    scanf("%d" , & tst);
    while(tst --)
        test();
    return 0;
}