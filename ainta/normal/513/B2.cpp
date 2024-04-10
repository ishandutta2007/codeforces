#include<stdio.h>
int n, w[100];
long long m;
int main()
{
    scanf("%d%lld", &n, &m);
    int i, be = 1, ed = n;
    m--;
    for (i = n - 2; i >= 0; i--){
        if (m & ((long long)1 << i)){
            w[ed] = n - 1 - i;
            ed--;
        }
        else{
            w[be] = n - 1 - i;
            be++;
        }
    }
    w[be] = n;
    for (i = 1; i <= n; i++)printf("%d ", w[i]);
}