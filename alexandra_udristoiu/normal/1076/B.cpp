#include<iostream>
using namespace std;
int i;
long long n, d;
int main(){
    cin>> n;
    for(i = 2; i * 1LL * i <= n; i++){
        if(n % i == 0){
            d = i;
            break;
        }
    }
    if(d == 0){
        d = n;
    }
    if(d == 2){
        cout<< n / 2;
    }
    else{
        cout<< 1 + (n - d) / 2;
    }
}