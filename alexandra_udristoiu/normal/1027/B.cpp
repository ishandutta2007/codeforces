#include<iostream>
using namespace std;
int n, q, x, y;
long long sum, m;
int main(){
    cin>> n >> q;
    m = n * 1LL * n;
    for(; q; q--){
        cin>> x >> y;
        sum = n * 1LL * (x - 1) + y;
        if((x + y) % 2 == 0){
            cout<< y / 2 + y % 2 + (x - 1) / 2 * 1LL * n + (x - 1) % 2 * 1LL * (n / 2 + n % 2) <<"\n";
        }
        else{
            cout<< m / 2 + m % 2 + y / 2 + y % 2 + (x - 1) / 2 * 1LL * n + (x - 1) % 2 * 1LL * (n / 2) <<"\n";
        }
    }
}