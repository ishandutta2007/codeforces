#include<iostream>
#define DIM 100005
using namespace std;
int n, k, i, sol;
int v[DIM], p[DIM], u[DIM];
int main(){
    cin>> n >> k;
    for(i = 1; i <= k; i++){
        cin>> v[i];
        u[ v[i] ] = i;
    }
    for(i = k; i >= 1; i--){
        p[ v[i] ] = i;
    }
    for(i = 1; i <= n; i++){
        if(p[i] == 0){
            sol++;
            if(i != 1){
                sol++;
            }
            if(i != n){
                sol++;
            }
        }
        else{
            if(i != 1 && u[i - 1] < p[i]){
                sol++;
            }
            if(i != n && u[i + 1] < p[i]){
                sol++;
            }
        }
    }
    cout<< sol;
}