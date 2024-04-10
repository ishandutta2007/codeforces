#include<iostream>
using namespace std;
int t, n, i, x;
long long a, b, sum, sumxor;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        sum = sumxor = 0;
        for(i = 1; i <= n; i++){
            cin>> x;
            sum += x;
            sumxor ^= x;
        }
        a = (1LL << 50);
        if(sum % 2 != 0){
            a++;
        }
        sum += a;
        sumxor ^= a;
        b = (sumxor * 2 - sum) / 2;
        cout<<"3\n"<< a <<" "<< b <<" "<< b <<"\n";
    }
}