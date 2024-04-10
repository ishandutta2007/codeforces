#include<iostream>
#define DIM 200005
using namespace std;
int n, i, t, ii, j, jj, sol;
char s[DIM];
int d[DIM][4];
int cost(char a, int b){
    if(a == 'L' && b == 0){
        return 0;
    }
    if(a == 'R' && b == 1){
        return 0;
    }
    return 1;
}
int verif(int a, int b, int c){
    if(a != b || b != c || c != a){
        return 1;
    }
    return 0;
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cin>> s + 1;
        sol = n;
        for(ii = 0; ii < 4; ii++){
            for(i = 1; i <= n; i++){
                d[i][0] = d[i][1] = d[i][2] = d[i][3] = n;
            }
            d[2][ii] = cost(s[1], ii / 2) + cost(s[2], ii % 2);
            for(i = 3; i <= n; i++){
                for(j = 0; j < 4; j++){
                    for(jj = 0; jj < 4; jj++){
                        if(j % 2 == jj / 2 && j * 2 + jj % 2 != 0 && j * 2 + jj % 2 != 7){
                            d[i][jj] = min(d[i][jj], d[i - 1][j] + cost(s[i], jj % 2) );
                        }
                    }
                }
            }
            for(j = 0; j < 4; j++){
                if( verif(ii / 2, ii % 2, j % 2) && verif(ii / 2, j / 2, j % 2) ){
                    sol = min(sol, d[n][j]);
                }
            }
        }
        cout<< sol <<"\n";
    }
}