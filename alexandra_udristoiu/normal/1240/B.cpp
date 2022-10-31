#include<iostream>
#define DIM 300005
#define f first
#define s second
using namespace std;
int n, t, i, m, sol;
int v[DIM], ff[DIM], w[DIM], nr[DIM];
pair<int, int> p[DIM];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
            p[i] = make_pair(0, 0);
            ff[i] = 0;
        }
        for(i = 1; i <= n; i++){
            ff[ v[i] ] = 1;
        }
        m = 0;
        for(i = 1; i <= n; i++){
            if(ff[i] == 1){
                m++;
                ff[i] = m;
            }
        }
        for(i = 1; i <= n; i++){
            v[i] = ff[ v[i] ];
            if(p[ v[i] ].f == 0){
                p[ v[i] ] = make_pair(i, i);
            }
            else{
                p[ v[i] ].s = i;
            }
        }
        sol = m;
        nr[m] = 1;
        for(i = m - 1; i >= 1; i--){
            if(p[i].s < p[i + 1].f){
                nr[i] = 1 + nr[i + 1];
            }
            else{
                nr[i] = 1;
            }
        }
        for(i = 0; i < m; i++){
            sol = min(sol, i + m - i - nr[i + 1]);
        }
        cout<< sol <<"\n";
    }
}