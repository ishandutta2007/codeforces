#include<iostream>
using namespace std;
int t, x, y, x2, y2, n, m;
long long sol;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> x >> y >> x2 >> y2;
        n = x2 - x + 1;
        m = y2 - y + 1;
        if(n < m){
            swap(n, m);
        }
        sol = m * 1LL * (m - 1) + (n - m + 1) * 1LL * m;
        sol -= n + m - 2;
        cout<< sol <<"\n";
    }
}