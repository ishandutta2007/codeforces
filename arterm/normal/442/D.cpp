//#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 1000100
#define T 50

int n;
int a[M][T];
int p[M], d[M];

void rep(int x){
    while (x > 1 && (a[x][d[x]] >= 2 || a[x][d[x] + 1] >= 1)){
        ++d[x];
        a[p[x]][d[x] - 1]--;
        a[p[x]][d[x]]++;
        x = p[x];
    }
}


int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    //ios_base::sync_with_stdio(0);
#endif

    scanf("%d", &n);
    int k = 1;

    for (int i = 2, x; i <= n + 1; ++i){
        scanf("%d", &x);
        d[i] = 1;
        p[i] = x;
        a[x][1]++;
        rep(x);
        if (a[1][k + 1])
            ++k;
        printf("%d ", k);
    }

    printf("\n");

    return 0;
}