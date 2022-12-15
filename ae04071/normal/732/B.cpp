#include <stdio.h>

int n, k;
int arr[500], res[500];

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    int ad = 0;
    res[0] = arr[0];
    for(int i = 1; i < n; i++) {
        res[i] = arr[i];
        if(res[i] + res[i-1] < k) {
            ad += k - res[i-1] - res[i];
            res[i] += k - res[i-1] - res[i];
        }
    }
    printf("%d\n", ad);
    for(int i =0 ; i < n; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}