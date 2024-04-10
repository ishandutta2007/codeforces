#include<iostream>
#include<algorithm>
using namespace std;
int n, i;
long long sol;
int v[300005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i <= n / 2; i++){
        sol += (v[i] + v[n - i + 1]) * 1LL * (v[i] + v[n - i + 1]);
    }
    cout<< sol;
}