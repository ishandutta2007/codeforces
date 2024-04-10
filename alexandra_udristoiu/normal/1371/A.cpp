#include<iostream>
using namespace std;
int t, n;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cout<< n / 2 + n % 2 <<"\n";
    }
}