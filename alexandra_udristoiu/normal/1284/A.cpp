#include<iostream>
using namespace std;
int n, m, i, q, x;
char a[25][15], b[25][15];
int main(){
    cin>> n >> m;
    for(i = 0; i < n; i++){
        cin>> a[i] + 1;
    }
    for(i = 0; i < m; i++){
        cin>> b[i] + 1;
    }
    cin>> q;
    for(; q; q--){
        cin>> x;
        x--;
        cout<< a[x % n] + 1 << b[x % m] + 1 << "\n";
    }
}