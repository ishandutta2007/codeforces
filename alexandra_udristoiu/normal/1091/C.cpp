#include<iostream>
#include<algorithm>
using namespace std;
int n, i, nr, x, m;
long long v[1000005];
int main(){
    cin>> n;
    for(i = 1; i <= n / i; i++){
        if(n % i == 0){
            x = i;
            v[++m] = n / x + (n / x) * 1LL * (n / x - 1) / 2 * x;
            x = n / i;
            v[++m] = n / x + (n / x) * 1LL * (n / x - 1) / 2 * x;
        }
    }
    sort(v + 1, v + m + 1);
    cout<< v[1] <<" ";
    for(i = 2; i <= m; i++){
        if(v[i] != v[i - 1]){
            cout<< v[i] <<" ";
        }
    }
}