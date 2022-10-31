#include<iostream>
#define val 1000000
using namespace std;
int n, i, x, sol;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        sol = max(sol, min(x - 1, val - x));
    }
    cout<< sol;
}