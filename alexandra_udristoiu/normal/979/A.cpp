#include<iostream>
using namespace std;
long long n;
int main(){
    cin>> n;
    if(n == 0){
        cout<< 0;
    }
    else{
        if(n % 2 == 1){
            cout<< n / 2 + 1;
        }
        else{
            cout<< n + 1;
        }
    }
}