#include<iostream>
#include<cstdio>
#define DIM (1 << 20) + 4
using namespace std;
int n, m, t, i, nr;
long long sol;
int v[DIM], niv[DIM], s[DIM];
int nivel(int x){
    if(2 * x >= (1 << n) || (v[2 * x] == 0 && v[2 * x + 1] == 0) ){
        return niv[x];
    }
    if(v[2 * x] > v[2 * x + 1]){
        return nivel(2 * x);
    }
    else{
        return nivel(2 * x + 1);
    }
}
void elim(int x){
    if( 2 * x >= (1 << n) || (v[2 * x] == 0 && v[2 * x + 1] == 0) ){
        v[x] = 0;
    }
    else{
        if(v[2 * x] > v[2 * x + 1]){
            v[x] = v[2 * x];
            elim(2 * x);
        }
        else{
            v[x] = v[2 * x + 1];
            elim(2 * x + 1);
        }
    }
}
int main(){
    scanf("%d", &t);
    for(; t; t--){
        scanf("%d%d", &n, &m);
        sol = 0;
        nr = 0;
        for(i = 1; i < (1 << n); i++){
            scanf("%d", &v[i]);
            sol += v[i];
            niv[i] = 1 + niv[i / 2];
        }
        for(i = 1; i < (1 << n); i++){
            if(v[i] == 0){
                continue;
            }
            while( nivel(i) > m){
                s[++nr] = i;
                sol -= v[i];
                elim(i);
            }
        }
        cout<< sol <<"\n";
        for(i = 1; i <= nr; i++){
            cout<< s[i] <<" ";
        }
        cout<<"\n";
    }
}