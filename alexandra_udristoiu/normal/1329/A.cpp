#include<iostream>
using namespace std;
int n, m, i, p;
long long sum;
int v[100005], sol[100005];
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> v[i];
        sum += v[i];
    }
    if(sum < n){
        cout<< -1;
        return 0;
    }
    p = n - v[m] + 1;
    sum -= v[m];
    sol[m] = p;
    for(i = m - 1; i >= 1; i--){
        p--;
        if(p == 0){
            cout<< -1;
            return 0;
        }
        sum -= v[i];
        if(sum < p){
            p = sum + 1;
        }
        p = min(p, n - v[i] + 1);
        sol[i] = p;
    }
    for(i = 1; i <= m; i++){
        cout<< sol[i] <<" ";
    }
}