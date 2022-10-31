#include<iostream>
#include<cstdio>
#define DIM 200005
using namespace std;
int n, i, ok, p, u, x, sol;
int ff[DIM], v[DIM];
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &x);
        ff[x] = 1;
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
        if(v[i] == 1){
            p = i;
        }
    }
    if(p != 0){
        ok = 1;
        for(i = p; i <= n; i++){
            if(v[i] != i - p + 1){
                ok = 0;
            }
        }
        for(i = n - p + 2; i <= n; i++){
            if(ff[i] == 0){
                ok = 0;
            }
            u++;
            ff[ v[u] ] = 1;
        }
        if(ok == 1){
            cout<< p - 1;
            return 0;
        }
        for(i = p; i <= n; i++){
            if(v[i] != 0){
                sol = max(sol, i - v[i] + 1);
            }
        }
        cout<< sol + n;
        return 0;
    }
    for(i = 1; i <= n; i++){
        if(v[i] != 0){
            sol = max(sol, i - v[i] + 1);
        }
    }
    cout<< sol + n;
}