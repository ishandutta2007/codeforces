#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
int a[400][400];
int b[400];
int res[400];
int n;

int f(int p, int h){
    int i;
    h++;
    for (i = 0; i < n; i++)
        if (a[p][i] == h)
            return i;
    return -1;
}
int f2(int h){
    int i;
    h++;
    for (i = 0; i < n; i++)
        if (b[i] == h)
            return i;
    return -1;
}


int main()
{
    int i, j, d;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < n; i++){
        d = -1;
        for (j = 0; j < n; j++){
            if (j == i)
                continue;
            if (d == -1){
                d = j;
                res[i] = d;
                continue;
            }
            if (f2(d) > f2(j)){
                d = j;
                if (f(i, j) < f(i, res[i]))
                    res[i] = d;
            }
        }
    }
    for (i = 0; i < n; i++)
        printf("%d ", res[i] + 1);


    return 0;
}