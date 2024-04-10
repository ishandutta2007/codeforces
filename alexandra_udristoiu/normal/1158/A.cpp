#include<iostream>
#include<algorithm>
#define DIM 100005
using namespace std;
int n, m, i;
long long sol;
int b[DIM], g[DIM];
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> b[i];
    }
    for(i = 1; i <= m; i++){
        cin>> g[i];
    }
    sort(b + 1, b + n + 1);
    sort(g + 1, g + m + 1);
    if(b[n] > g[1]){
        cout<< -1;
        return 0;
    }
    for(i = 1; i < n; i++){
        sol += b[i] * 1LL * m;
    }
    for(i = 1; i <= m; i++){
        sol += g[i];
    }
    if(b[n] != g[1]){
        sol -= g[1] - b[n];
        sol += g[1] - b[n - 1];
    }
    cout<< sol;
}