#include<iostream>
#include<cstdio>
using namespace std;
int n, i, u;
long long sum, sol, x, nr;
int v[1000005];
long long suma(int n){
    return n * 1LL * (n + 1) / 2;
}
int main(){
    cin>> n >> x;
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    u = 1;
    for(i = 1; i <= n; i++){
        nr -= v[i - 1];
        sum -= suma(v[i - 1]);
        while(nr < x){
            nr += v[u];
            sum += suma(v[u]);
            u++;
            if(u == n + 1){
                u = 1;
            }
        }
        if(nr - x <= v[i]){
            sol = max(sol, sum - suma(nr - x) );
        }
    }
    cout<< sol;
}