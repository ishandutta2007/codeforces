#include<iostream>
#include<cstdio>
using namespace std;
int n, m, i, j, ii, jj, k;
int main(){
    cin>> n >> m;
    for(i = 1; i <= n / 2; i++){
        ii = n - i + 1;
        j = 1;
        jj = m + 1;
        for(k = 1; k <= m + m; k++){
            if(k % 2 == 0){
                printf("%d %d\n", ii, jj);
                j++;
            }
            else{
                printf("%d %d\n", i, j);
                jj--;
            }
        }
    }
    if(n % 2 == 1){
        i = n / 2 + 1;
        j = 1;
        jj = m + 1;
        for(k = 1; k <= m; k++){
            if(k % 2 == 1){
                printf("%d %d\n", i, j);
                jj--;
            }
            else{
                printf("%d %d\n", i, jj);
                j++;
            }
        }
    }
}