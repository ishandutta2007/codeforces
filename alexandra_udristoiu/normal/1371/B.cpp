#include<iostream>
using namespace std;
int t, n, k;
long long sol;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> k;
        if(k >= n){
            sol = (n - 1) * 1LL * n / 2 + 1;
        }
        else{
            sol = k * 1LL * (k + 1) / 2;
        }
        cout<< sol <<"\n";
    }
}