#include<iostream>
#define DIM 100005
using namespace std;
int n, c, d, i, u;
long long sum, sol;
int poz[DIM];
char tip[DIM];
int main(){
    cin>> n >> c >> d;
    for(i = 1; i <= n; i++){
        cin>> poz[i] >> tip[i];
    }
    cin>> poz[i];
    u = n + 1;
    sol = d * 1LL * n;
    for(i = n; i >= 1; i--){
        if(tip[i - 1] == tip[i]){
            sum += min(d, c * (poz[u] - poz[i]) );
        }
        else{
            sum += c * (poz[u] - poz[i]);
            u = i;
        }
        sol = min(sol, sum + (i - 1) * 1LL * d);
    }
    cout<< sol;
    return 0;
}