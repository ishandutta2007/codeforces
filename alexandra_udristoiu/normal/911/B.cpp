#include<iostream>
using namespace std;
int n, i, a, b, sol;
int main(){
    cin>> n >> a >> b;
    for(i = 1; i < n; i++){
        sol = max(sol, min(a / i, b / (n - i) ) );
    }
    cout<< sol;
}