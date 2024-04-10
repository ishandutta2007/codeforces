#include<iostream>
#include<algorithm>
#include<cmath>
#define DIM 200005
using namespace std;
int n, q, m, nr, e, i, j, r, sq, t, st, dr;
int v[DIM], aux[DIM], a[DIM], ff[DIM], num[DIM], sol[DIM];
struct str{
    int nr, st, dr, ind;
};
str w[DIM], op[DIM];
void upd(int x, int y){
    num[ ff[x] ]--;
    ff[x] += y;
    num[ ff[x] ]++;
}
int cautbin(int x){
    int st = 1, dr = e, mid;
    while(st <= dr){
        mid = (st + dr) / 2;
        if(a[mid] == x){
            return mid;
        }
        if(a[mid] < x){
            st = mid + 1;
        }
        else{
            dr = mid - 1;
        }
    }
}
int cmp(str a, str b){
    if(a.nr / r != b.nr / r){
        return a.nr < b.nr;
    }
    if(a.st / r != b.st / r){
        return a.st < b.st;
    }
    return a.dr < b.dr;
}
int main(){
    cin>> n >> q;
    for(i = 0; i < n; i++){
        cin>> v[i];
        aux[i] = v[i];
        a[i + 1] = v[i];
    }
    for(; q; q--){
        cin>> t >> st >> dr;
        st--;
        dr--;
        if(t == 1){
            w[++m] = {nr, st, dr, m};
        }
        else{
            dr++;
            op[++nr] = {st, v[st], dr, 0};
            v[st] = dr;
            a[nr + n] = dr;
        }
    }
    sort(a + 1, a + n + nr + 1);
    e = 1;
    for(i = 2; i <= n + nr; i++){
        if(a[i] != a[e]){
            a[++e] = a[i];
        }
    }
    for(i = 0; i < n; i++){
        aux[i] = cautbin(aux[i]);
    }
    for(i = 1; i <= nr; i++){
        op[i].st = cautbin(op[i].st);
        op[i].dr = cautbin(op[i].dr);
    }
    for(i = 1; i <= n; i++){
        if(n * 1LL * n < i * 1LL * i * i){
            r = i - 1;
            break;
        }
    }
    sort(w + 1, w + m + 1, cmp);
    for(i = 0; i < n; i++){
        v[i] = aux[i];
    }
    for(i = 1; i <= w[1].nr; i++){
        v[ op[i].nr ] = op[i].dr;
    }
    sq = 2 * sqrt(n * 1.0);
    for(i = w[1].st; i <= w[1].dr; i++){
        upd(v[i], 1);
    }
    for(i = 1; i <= sq; i++){
        if(num[i] == 0){
            sol[ w[1].ind ] = i;
            break;
        }
    }
    for(i = 2; i <= m; i++){
        for(j = w[i - 1].nr + 1; j <= w[i].nr; j++){
            if(w[i - 1].st <= op[j].nr && w[i - 1].dr >= op[j].nr){
                upd(v[ op[j].nr ], -1);
                v[ op[j].nr ] = op[j].dr;
                upd(v[ op[j].nr ], 1);
            }
            else{
                v[ op[j].nr ] = op[j].dr;
            }
        }
        for(j = w[i - 1].nr; j > w[i].nr; j--){
            if(w[i - 1].st <= op[j].nr && w[i - 1].dr >= op[j].nr){
                upd(v[ op[j].nr ], -1);
                v[ op[j].nr ] = op[j].st;
                upd(v[ op[j].nr ], 1);
            }
            else{
                v[ op[j].nr ] = op[j].st;
            }
        }
        for(j = w[i - 1].st; j < w[i].st; j++){
            upd(v[j], -1);
        }
        for(j = w[i].st; j < w[i - 1].st; j++){
            upd(v[j], 1);
        }
        for(j = w[i - 1].dr + 1; j <= w[i].dr; j++){
            upd(v[j], 1);
        }
        for(j = w[i - 1].dr; j > w[i].dr; j--){
            upd(v[j], -1);
        }
        for(j = 1; j <= sq; j++){
            if(num[j] == 0){
                sol[ w[i].ind ] = j;
                break;
            }
        }
    }
    for(i = 1; i <= m; i++){
        cout<< sol[i] <<"\n";
    }
}