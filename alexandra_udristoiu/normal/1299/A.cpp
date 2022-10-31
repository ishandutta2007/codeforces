#include<iostream>
#define DIM 100005
using namespace std;
int n, i, val, sol, p;
int v[DIM], sp[DIM], su[DIM];
int main(){
    cin>> n;
    sp[0] = su[n + 1] = (1 << 30) - 1;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        sp[i] = (sp[i - 1] & (sp[0] - v[i]) );
    }
    for(i = n; i >= 1; i--){
        su[i] = (su[i + 1] & (sp[0] - v[i]) );
    }
    sol = -1;
    for(i = 1; i <= n; i++){
        val = (v[i] & sp[i - 1] & su[i + 1]);
        if(val > sol){
            sol = val;
            p = i;
        }
    }
    cout<< v[p] <<" ";
    for(i = 1; i <= n; i++){
        if(i != p){
            cout<< v[i] <<" ";
        }
    }
}