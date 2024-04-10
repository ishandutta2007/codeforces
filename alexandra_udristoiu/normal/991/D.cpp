#include<iostream>
#include<cstring>
using namespace std;
int n, i, ii, x, sol;
int d[105][4];
char s[2][105];
int slv(int di1, int dj1, int di2, int dj2, int di3, int dj3){
    if(s[dj1][i + di1] == 'X' || s[dj2][i + di2] == 'X' || s[dj3][i + di3] == 'X'){
        return -1;
    }
    if(di1 == 0 && ( (ii >> dj1) & 1) == 1){
        return -1;
    }
    if(di2 == 0 && ( (ii >> dj2) & 1) == 1){
        return -1;
    }
    int x = 0;
    if(di2 == 1){
        x += (1 << dj2);
    }
    if(di3 == 1){
        x += (1 << dj3);
    }
    return x;
}
int main(){
    cin>> s[0] + 1;
    cin>> s[1] + 1;
    n = strlen(s[0] + 1);
    for(i = 1; i < n; i++){
        for(ii = 0; ii < 4; ii++){
            d[i + 1][0] = max(d[i + 1][0], d[i][ii]);
            x = slv(0, 0, 0, 1, 1, 0);
            if(x != -1){
                d[i + 1][x] = max(d[i + 1][x], d[i][ii] + 1);
            }
            x = slv(0, 0, 0, 1, 1, 1);
            if(x != -1){
                d[i + 1][x] = max(d[i + 1][x], d[i][ii] + 1);
            }
            x = slv(0, 0, 1, 0, 1, 1);
            if(x != -1){
                d[i + 1][x] = max(d[i + 1][x], d[i][ii] + 1);
            }
            x = slv(0, 1, 1, 0, 1, 1);
            if(x != -1){
                d[i + 1][x] = max(d[i + 1][x], d[i][ii] + 1);
            }
        }
    }
    sol = max(d[n][0], d[n][1]);
    sol = max(sol, max(d[n][2], d[n][3]) );
    cout<< sol;
}