#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
double P[110], PP, PP2, MAX;
int n;
int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)scanf("%lf", &P[i]);
    sort(P, P + n);
    if (P[n - 1] == 1.0){
        printf("%.13lf\n", 1.0);
        return 0;
    }
    for (i = 0; i < n; i++){
        PP = 1;
        PP2 = 0;
        for (j = i; j < n; j++){
            PP = PP * (1 - P[j]);
            PP2 += P[j] / (1 - P[j]);
        }
        if (MAX < PP*PP2) MAX = PP*PP2;
    }
    printf("%.13lf\n", MAX);
}