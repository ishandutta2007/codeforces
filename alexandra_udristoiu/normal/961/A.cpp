#include<iostream>
using namespace std;
int n, m, x, sol, i;
int c[1005];
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x;
        c[x]++;
    }
    sol = m;
    for(i = 1; i <= n; i++){
        sol = min(sol, c[i]);
    }
    cout<< sol;
}