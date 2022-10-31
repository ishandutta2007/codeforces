#include<iostream>
using namespace std;
int n, i, maxim1, maxim2, x;
long long sum;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        sum += x;
    }
    for(i = 1; i <= n; i++){
        cin>> x;
        if(maxim1 < x){
            maxim2 = maxim1;
            maxim1 = x;
        }
        else{
            if(maxim2 < x){
                maxim2 = x;
            }
        }
    }
    if(maxim1 + maxim2 >= sum){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}