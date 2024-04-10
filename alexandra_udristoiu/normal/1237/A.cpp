#include<iostream>
#define DIM 14000
using namespace std;
int n, i, x, sum;
int ok[DIM], v[DIM];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        v[i] = x / 2;
        if(x % 2 != 0){
            ok[i] = 1;
        }
        if(x < 0 && x % 2 != 0){
            v[i]--;
        }
        sum += v[i];
    }
    for(i = 1; i <= n; i++){
        if(sum == 0){
            break;
        }
        if(ok[i] == 1){
            v[i]++;
            sum++;
        }
    }
    for(i = 1; i <= n; i++){
        cout<< v[i] <<"\n";
    }
}