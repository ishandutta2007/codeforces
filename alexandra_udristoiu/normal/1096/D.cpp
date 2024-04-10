#include<iostream>
#define DIM 100005
using namespace std;
int n, i, ii;
char s[DIM];
int c[DIM];
long long d[DIM][4], sol;
char sir[] = "hhard";
int main(){
    cin>> n;
    cin>> s + 1;
    for(i = 1; i <= n; i++){
        cin>> c[i];
    }
    d[0][1] = d[0][2] = d[0][3] = 1000000000000000LL;
    for(i = 1; i <= n; i++){
        for(ii = 0; ii < 4; ii++){
            d[i][ii] = d[i - 1][ii];
            if(ii != 0 && s[i] == sir[ii]){
                d[i][ii] = min(d[i][ii], d[i - 1][ii - 1]);
            }
            if(sir[ii + 1] == s[i]){
                d[i][ii] += c[i];
            }
        }
    }
    sol = min(d[n][0], d[n][1]);
    sol = min(sol, d[n][2]);
    sol = min(sol, d[n][3]);
    cout<< sol;
}