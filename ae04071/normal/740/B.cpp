#include <stdio.h>

int n, m;
int arr[100];

int main()
{
    scanf("%d %d",&n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int a, b;

    int t = 0;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        int res = 0;
        for(int j = a; j <= b; j++) {
            res += arr[j];
        }
        if(res > 0) t += res;
    }
    printf("%d\n", t);

    return 0;
}