#include<iostream>
#include<algorithm>
using namespace std;
int n, q, x, i;
long long sum;
int v[300005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        sum += v[i];
    }
    sort(v + 1, v + n + 1);
    cin>> q;
    for(; q; q--){
        cin>> x;
        cout<< sum - v[n - x + 1] <<"\n";
    }
}