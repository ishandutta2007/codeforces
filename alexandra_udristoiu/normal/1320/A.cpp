#include<iostream>
using namespace std;
int n, i, m, x;
long long sum[600005], sol;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        m = max(m, x);
        sum[x - i + n] += x;
    }
    for(i = 0; i <= m + n; i++){
        sol = max(sol, sum[i]);
    }
    cout<< sol;
}