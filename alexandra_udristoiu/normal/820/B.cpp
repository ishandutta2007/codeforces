#include<iostream>
using namespace std;
int n, a, i, sol2;
double u, x, sol;
double modul(double x){
    if(x > 0){
        return x;
    }
    return -x;
}
int main(){
    cin>> n >> a;
    u = (n - 2) * 180.0 / n;
    x = u / (n - 2);
    sol = 360;
    for(i = n - 1; i > 1; i--){
        if(modul(sol - a) > modul(u - a)){
            sol = u;
            sol2 = i;
        }
        u -= x;
    }
    cout<< sol2 <<" "<< n <<" 1";
    return 0;
}