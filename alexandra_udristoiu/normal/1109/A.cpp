#include<iostream>
using namespace std;
int n, i, x, sum;
long long nr;
int d[(1 << 20) + 5][2];
int main(){
    cin>> n;
    d[0][0] = 1;
    for(i = 1; i <= n; i++){
        cin>> x;
        sum ^= x;
        nr += d[sum][i % 2];
        d[sum][i % 2]++;
    }
    cout<< nr;
}