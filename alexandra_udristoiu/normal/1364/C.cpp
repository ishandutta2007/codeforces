#include<iostream>
#define DIM 100005
using namespace std;
int n, i, u;
int v[DIM], sol[DIM], ff[DIM];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        ff[ v[i] ] = 1;
    }
    u = 1;
    for(i = 1; i <= n; i++){
        if(v[i] != v[i - 1]){
            sol[i] = v[i - 1];
        }
        else{
            while(u <= n && ff[u] == 1){
                 u++;
            }
            sol[i] = u;
            ff[u] = 1;
        }
    }
    for(i = 1; i <= n; i++){
        cout<< sol[i] <<" ";
    }
}