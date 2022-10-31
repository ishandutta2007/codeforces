#include<iostream>
using namespace std;
int t;
long long n, k, sol;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> k;
        sol = 0;
        while(n != 0){
            sol += n % k + 1;
            n /= k;
        }
        cout<< sol - 1 <<"\n";
    }
}