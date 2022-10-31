#include<iostream>
#include<algorithm>
#define DIM 100005
using namespace std;
int nr, ng, nb, i, t;
long long sol;
int r[DIM], g[DIM], b[DIM];
long long pt(int x){
    return x * 1LL * x;
}
long long calc(int x, int y, int z){
    return pt(r[x] - g[y]) + pt(r[x] - b[z]) + pt(g[y] - b[z]);
}
void solve(){
    int i, u1 = 1, u2 = 1;
    for(i = 1; i <= nr; i++){
        while(u1 < ng && g[u1 + 1] < r[i]){
            u1++;
        }
        while(u2 < nb && b[u2 + 1] < r[i]){
            u2++;
        }
        sol = min(sol, calc(i, u1, u2) );
        if(u1 != ng){
            sol = min(sol, calc(i, u1 + 1, u2) );
        }
        if(u2 != nb){
            sol = min(sol, calc(i, u1, u2 + 1) );
        }
        if(u2 != nb && u1 != ng){
            sol = min(sol, calc(i, u1 + 1, u2 + 1) );
        }
    }
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> nr >> ng >> nb;
        for(i = 1; i <= nr; i++){
            cin>> r[i];
        }
        for(i = 1; i <= ng; i++){
            cin>> g[i];
        }
        for(i = 1; i <= nb; i++){
            cin>> b[i];
        }
        sort(r + 1, r + nr + 1);
        sort(g + 1, g + ng + 1);
        sort(b + 1, b + nb + 1);
        sol = 2000000000000000000LL;
        solve();
        for(i = 1; i <= max(ng, nr); i++){
            swap(r[i], g[i]);
        }
        swap(nr, ng);
        solve();
        for(i = 1; i <= max(nb, nr); i++){
            swap(r[i], b[i]);
        }
        swap(nr, nb);
        solve();
        cout<< sol <<"\n";
    }
}