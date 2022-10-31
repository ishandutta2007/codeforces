#include<fstream>
#include<iostream>
#include<algorithm>
#define DIM 200005
using namespace std;
int n, i, j, sum, aux;
long long sol;
int v[DIM];
char s[DIM][33];
struct trie{
    int nr;
    trie *f[2];
    trie(){
        nr = 0;
        f[0] = f[1] = NULL;
    }
};
trie *r;
//ifstream fin("date.in");
//ofstream fout("date.out");
void adauga(trie *r, int i, int p){
    if(p != 0){
        if(r->f[ s[i][p] ] == NULL){
            r->f[ s[i][p] ] = new trie;
        }
        adauga(r->f[ s[i][p] ], i, p - 1);
    }
}
void upd(trie *r, int i, int p, int val){
    if(p != 0){
        r->f[ s[i][p] ]->nr += val;
        upd(r->f[ s[i][p] ], i, p - 1, val);
    }
}
void cauta(trie *r, int i, int p){
    if(p != 0){
        if(r->f[ s[i][p] ] != NULL && r->f[ s[i][p] ]->nr != 0){
            cauta(r->f[ s[i][p] ], i, p - 1);
        }
        else{
            sum += (1 << (p - 1) );
            cauta(r->f[1 - s[i][p] ], i, p - 1);
        }
    }
}
void solve(int st, int dr, int b){
    int i, mid = dr;
    for(i = st; i <= dr; i++){
        if( ( (v[i] >> (b - 1) ) & 1) == 1){
            mid = i - 1;
            break;
        }
    }
    if(b == 1){
        if(mid != st - 1 && mid != dr){
            sol++;
        }
        return;
    }
    if(mid == st - 1 || mid == dr){
        solve(st, dr, b - 1);
    }
    else{
        solve(st, mid, b - 1);
        solve(mid + 1, dr, b - 1);
        for(i = st; i <= mid; i++){
            upd(r, i, 30, 1);
        }
        int minim = (1 << 30);
        for(i = mid + 1; i <= dr; i++){
            sum = 0;
            cauta(r, i, 30);
            minim = min(minim, sum);
        }
        sol += minim;
        for(i = st; i <= mid; i++){
            upd(r, i, 30, -1);
        }
    }
}
int main(){
    cin>> n;
    r = new trie;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i <= n; i++){
        aux = v[i];
        for(j = 1; j <= 30; j++){
            s[i][j] = aux % 2;
            aux /= 2;
        }
        adauga(r, i, 30);
    }
    solve(1, n, 30);
    cout<< sol;
    return 0;
}