#include<iostream>
#include<algorithm>
using namespace std;
int n, m, i, p, t, nr;
long long sol;
int poz[100005];
struct str{
    int a, c, ind;
};
str v[100005];
int cmp(str x, str y){
    if(x.c == y.c){
        return x.ind < y.ind;
    }
    return x.c < y.c;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> v[i].a;
        v[i].ind = i;
    }
    for(i = 1; i <= n; i++){
        cin>> v[i].c;
    }
    sort(v + 1, v + n + 1, cmp);
    for(i = 1; i <= n; i++){
        poz[ v[i].ind ] = i;
    }
    p = 1;
    for(; m; m--){
        sol = 0;
        cin>> t >> nr;
        t = poz[t];
        if(v[t].a >= nr){
            v[t].a -= nr;
            sol = nr * 1LL * v[t].c;
        }
        else{
            sol = v[t].a * 1LL * v[t].c;
            nr -= v[t].a;
            v[t].a = 0;
            while(p <= n){
                if(v[p].a >= nr){
                    sol += nr * 1LL * v[p].c;
                    v[p].a -= nr;
                    nr = 0;
                    break;
                }
                sol += v[p].a * 1LL * v[p].c;
                nr -= v[p].a;
                v[p].a = 0;
                p++;
            }
            if(nr > 0){
                sol = 0;
            }
        }
        cout<< sol <<"\n";
    }
    return 0;
}