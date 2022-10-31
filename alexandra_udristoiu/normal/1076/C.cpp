#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int t;
long double sol1, sol2, delta, a, b, c, d;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> d;
        a = 1;
        b = -d;
        c = d;
        delta = b * b - 4 * a * c;
        if(delta < 0){
            cout<<"N\n";
            continue;
        }
        sol1 = (-b - sqrt(delta) ) / (2 * a);
        sol2 = (-b + sqrt(delta) ) / (2 * a);
        if(sol1 < 0 || sol2 < 0){
            cout<<"N\n";
            continue;
        }
        cout<<"Y ";
        if(sol1 > sol2){
            cout<< setprecision(9) << fixed << sol1 <<" "<< setprecision(9) << fixed << sol2 <<"\n";
        }
        else{
            cout<< setprecision(9) << fixed << sol2 <<" "<< setprecision(9) << fixed << sol1 <<"\n";
        }
    }
}