#include<iostream>
using namespace std;
int t, x;
long long k;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> k >> x;
        cout<< k * 9 - 9 + x <<"\n";
    }
}