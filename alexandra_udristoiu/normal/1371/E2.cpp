#include<iostream>
#include<algorithm>
#define DIM 100005
using namespace std;
int n, p, x, i, st, dr, minim, nr, dif;
int v[DIM], a[DIM], ff[DIM], sol[DIM];
int main(){
    cin>> n >> p;
    for(i = 1; i <= n; i++){
        cin>> a[i];
    }
    sort(a + 1, a + n + 1);
    minim = n;
    for(i = 1; i <= n; i++){
        x = max(x, a[i] - i + 1);
    }
    for(i = 1; i <= n; i++){
        v[i] = x + n - a[i];
    }
    sort(v + 1, v + n + 1);
    for(i = 2; i <= n; i++){
        v[i] -= i - 1;
    }
    for(i = 1; i <= n; i++){
        if(n - i + 1 >= v[i]){
            dr = n - i + 1 - v[i];
        }
        else{
            dr = -1;
        }
        if( (n - i + 1) % p == 0){
            minim = min(minim, dr);
        }
        if(v[i] % p == 0){
            st = 0;
        }
        else{
            st = p - v[i] % p;
        }
        if(st <= dr){
            ff[st]++;
            dif = (dr - st) / p + 1;
            ff[st + dif * p ]--;
        }
    }
    for(i = 0; i < minim; i++){
        if(i >= p){
            ff[i] += ff[i - p];
        }
        if(ff[i] == 0){
            sol[++nr] = x + i;
        }
    }
    cout<< nr <<"\n";
    for(i = 1; i <= nr; i++){
        cout<< sol[i] <<" ";
    }
}