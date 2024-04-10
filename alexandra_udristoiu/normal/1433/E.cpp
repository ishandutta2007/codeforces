#include<iostream>
using namespace std;
int n, i;
long long sol;
int main(){
    cin>> n;
    sol = 1;
    for(i = n / 2 + 1; i <= n; i++){
        sol *= i;
    }
    for(i = 1; i <= n / 2; i++){
        sol /= i;
    }
    sol /= 2;
    n = n / 2 - 1;
    for(i = 1; i <= n; i++){
        sol *= i;
        sol *= i;
    }
    cout<< sol;
}