#include<iostream>
#define DIM 1000005
using namespace std;
int n, i, j, aux, st, sol;
int minim[DIM], c[DIM];
int main(){
    cin>> n;
    for(i = 2; i <= n; i++){
        minim[i] = n + 1;
    }
    for(i = 2; i <= n; i++){
        if(c[i] == 0){
            for(j = i + i; j <= n; j += i){
                c[j] = 1;
                minim[j] = min(minim[j], j - i + 1);
            }
        }
    }
    st = n;
    aux = n;
    for(i = 2; i <= n; i++){
        if(aux % i == 0){
            st = min(st, n - i + 1);
            while(aux % i == 0){
                aux /= i;
            }
        }
    }
    sol = n;
    for(i = st; i <= n; i++){
        sol = min(sol, minim[i]);
    }
    cout<< sol;
}