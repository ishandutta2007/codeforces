#include<iostream>
using namespace std;
int n, k, i, sum, sol, x;
int s[100005], v[100005];
int main(){
    cin>> n >> k;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 1; i <= n; i++){
        cin>> x;
        s[i] = s[i - 1];
        if(x == 0){
            s[i] += v[i];
        }
        else{
            sum += v[i];
        }
    }
    for(i = 1; i <= n - k + 1; i++){
        sol = max(sol, s[i + k - 1] - s[i - 1]);
    }
    cout<< sol + sum;
}