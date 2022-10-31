#include<iostream>
using namespace std;
int n, i, minim, sol, p;
int v[100005];
int main(){
    cin>> n;
    minim = 1000000000;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        minim = min(minim, v[i]);
    }
    sol = n;
    for(i = 1; i <= n; i++){
        if(minim == v[i]){
            if(p != 0){
                sol = min(sol, i - p);
            }
            p = i;
        }
    }
    cout<< sol;
}