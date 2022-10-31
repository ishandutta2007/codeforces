#include<iostream>
#define mod 998244353
using namespace std;
int n, i, k, m, num, x;
long long sum;
int p[200005];
int main(){
    cin>> n >> k;
    for(i = n; i >= n - k + 1; i--){
        sum += i;
    }
    num = 1;
    for(i = 1; i <= n; i++){
        cin>> x;
        if(x >= n - k + 1){
            p[++m] = i;
        }
    }
    p[k + 1] = n + 1;
    for(i = 1; i < k; i++){
        num = num * 1LL * (p[i + 1] - p[i]) % mod;
    }
    cout<< sum <<" "<< num;
}