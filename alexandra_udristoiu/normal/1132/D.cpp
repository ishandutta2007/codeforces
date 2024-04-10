#include<iostream>
#include<cstdio>
#define DIM 200005
using namespace std;
int n, k, i;
long long st, dr, mid;
int b[DIM];
long long a[DIM], tt[DIM];
struct str{
    int p;
    long long s, t;
};
str h[DIM], aux;
void upd(int pos){
    int c = pos, p = c / 2;
    while(p > 0 && h[p].t > h[c].t){
        aux = h[p];
        h[p] = h[c];
        h[c] = aux;
        c = p;
        p = c / 2;
    }
}
void elim(){
    int p = 1, c = 2;
    while(c <= n){
        if(c + 1 <= n && h[c + 1].t < h[c].t){
            c++;
        }
        if(h[c].t < h[p].t){
            aux = h[p];
            h[p] = h[c];
            h[c] = aux;
            p = c;
            c = p + p;
        }
        else{
            break;
        }
    }
}
int verif(long long val){
    int i;
    for(i = 1; i <= n; i++){
        h[i] = {i, a[i], tt[i]};
        upd(i);
    }
    for(i = 1; i < k; i++){
        if(h[1].t < i){
            return 0;
        }
        h[1].s += val;
        h[1].t = h[1].s / b[ h[1].p ] + 1;
        elim();
    }
    if(h[1].t < k){
        return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++){
        scanf("%I64d ", &a[i]);
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &b[i]);
        tt[i] = a[i] / b[i] + 1;
    }
    st = 0;
    dr = 10000000000000LL;
    while(st <= dr){
        mid = (st + dr) / 2;
        if(verif(mid)){
            dr = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    if(st >= 10000000000000LL){
        cout<< -1;
    }
    else{
        cout<< st;
    }
}