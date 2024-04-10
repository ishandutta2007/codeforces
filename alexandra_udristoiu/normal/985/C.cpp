#include<iostream>
#include<algorithm>
using namespace std;
int n, k, i, u, dif;
long long sol;
int v[100005];
int main(){
    cin>> n >> k >> dif;
    for(i = 1; i <= n * k; i++){
        cin>> v[i];
    }
    sort(v + 1, v + n * k + 1);
    u = n * k;
    for(i = 2; i <= n * k; i++){
        if(v[i] - v[1] > dif){
            u = i - 1;
            break;
        }
    }
    if(u < n){
        cout<< 0;
        return 0;
    }
    for(i = n; i >= 1; i--){
        u = min(u, n * k - k * (n - i + 1) + 1);
        sol += v[u];
        u--;
    }
    cout<< sol;
}