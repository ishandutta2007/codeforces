#include<iostream>
using namespace std;
int t, n, i, x, sum, maxim, val, minim, sol;
int fmin[10005], fmax[10005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> x;
        sol = -1;
        for(i = 0; i < x; i++){
            fmin[i] = n + 1;
            fmax[i] = -1;
        }
        sum = 0;
        fmin[0] = fmax[0] = 0;
        for(i = 1; i <= n; i++){
            cin>> val;
            sum = (sum + val) % x;
            fmin[sum] = min(fmin[sum], i);
            fmax[sum] = i;
        }
        minim = fmin[0];
        maxim = fmax[0];
        for(i = 1; i < x; i++){
            sol = max(sol, fmax[i] - minim);
            sol = max(sol, maxim - fmin[i]);
            maxim = max(maxim, fmax[i]);
            minim = min(minim, fmin[i]);
        }
        cout<< sol <<"\n";
    }
}