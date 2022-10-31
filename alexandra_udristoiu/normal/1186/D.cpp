#include<iostream>
#include<cmath>
using namespace std;
int n, i, sum;
int v[100005], ok[100005];
double x;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        v[i] = floor(x);
        sum += v[i];
        if(v[i] == x){
            ok[i] = 1;
        }
    }
    for(i = 1; i <= n; i++){
        if(sum == 0){
            break;
        }
        if(ok[i] == 0){
            v[i]++;
            sum++;
        }
    }
    for(i = 1; i <= n; i++){
        cout<< v[i] <<"\n";
    }
}