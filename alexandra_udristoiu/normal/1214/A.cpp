#include<iostream>
using namespace std;
int n, d, e, sol, i;
int main(){
    cin>> n >> d >> e;
    e *= 5;
    sol = n;
    for(i = 0; i <= n; i += e){
        sol = min(sol, (n - i) % d );
    }
    cout<< sol;
}