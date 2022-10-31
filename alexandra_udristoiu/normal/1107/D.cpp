#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
int n, i, j, nr, sol, jj;
char s[1405];
bitset<5205> a[5205];
int cmmdc(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%s", s + 1);
        for(j = 1; j <= n / 4; j++){
            if(s[j] >= '0' && s[j] <= '9'){
                s[j] = s[j] - '0';
            }
            else{
                s[j] = 10 + s[j] - 'A';
            }
            for(jj = 0; jj < 4; jj++){
                a[i][j * 4 - jj] = ( (s[j] >> jj) & 1);
            }
        }
    }
    for(i = 1; i <= n; i++){
        nr = 1;
        for(j = 2; j <= n; j++){
            if(a[i][j] == a[i][j - 1]){
                nr++;
            }
            else{
                sol = cmmdc(sol, nr);
                nr = 1;
            }
        }
        sol = cmmdc(sol, nr);
    }
    for(j = 1; j <= n; j++){
        nr = 1;
        for(i = 2; i <= n; i++){
            if(a[i][j] == a[i - 1][j]){
                nr++;
            }
            else{
                sol = cmmdc(sol, nr);
                nr = 1;
            }
        }
        sol = cmmdc(sol, nr);
    }
    cout<< sol;
}