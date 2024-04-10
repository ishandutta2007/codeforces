#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[201000], ck;
int main(){
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &w[i]);
        w[i] += i;
    }
    sort(w + 1, w + n + 1);
    for (i = 1; i <= n; i++){
        w[i] -= i;
        if (i > 1 && w[i] < w[i - 1])ck = 1;
    }
    if (ck)printf(":(\n");
    else{
        for (i = 1; i <= n; i++)printf("%d ", w[i]);
    }
}