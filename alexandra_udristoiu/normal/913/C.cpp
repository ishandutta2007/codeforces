#include<iostream>
using namespace std;
int n, m, i, x;
long long c[35], d[35];
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> c[i];
    }
    for(i = 2; i <= n; i++){
        c[i] = min(c[i], 2 * c[i - 1]);
    }
    for(i = n + 1; i <= 31; i++){
        c[i] = 2 * c[i - 1];
    }
    n = 31;
    for(i = 1; i <= n; i++){
        x = m % 2;
        m /= 2;
        d[i] = min(c[i] * x + d[i - 1], c[i] * (x + 1) );
    }
    cout<< d[n];
}