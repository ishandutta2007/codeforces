#include<iostream>
using namespace std;
long long n, k, x;
int main(){
    cin>> n >> k;
    x = n / k;
    if(x % 2 == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}