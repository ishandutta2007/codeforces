#include<iostream>
#define DIM 500005
using namespace std;
int n, i, x, p;
long long sum, sum2;
int v[DIM];
int main(){
    cin>> n;
    for(i = 1; i <= n / 2 + n % 2; i++){
        cin>> v[i];
    }
    cin>> x;
    for(; i <= n; i++){
        v[i] = x;
    }
    if(x > 0){
        for(i = 1; i <= n; i++){
            sum += v[i];
        }
        if(sum > 0){
            cout<< n;
        }
        else{
            cout<< -1;
        }
    }
    else{
        for(i = n; i >= 1; i--){
            sum += v[i];
            sum2 += v[i];
            if(p != 0){
                sum -= v[i + p];
                if(sum <= 0){
                    p = 0;
                    sum = sum2;
                }
            }
            else{
                if(sum > 0){
                    p = n - i + 1;
                }
            }
        }
        if(p == 0){
            cout<< -1;
        }
        else{
            cout<< p;
        }
    }
}