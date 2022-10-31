#include<iostream>
using namespace std;
int n, i, x, j, sol;
char s[35];
int v[300005];
struct trie{
    int nr;
    trie *f[2];
    trie(){
        nr = 0;
        f[0] = f[1] = NULL;
    }
};
trie *r;
void adauga(trie *r, char *s){
    if(*s == -1){
        r->nr++;
    }
    else{
        if(r->f[*s] == NULL){
            r->f[*s] = new trie;
        }
        adauga(r->f[*s], s + 1);
        r->nr++;
    }
}
void solve(trie *r, char *s, int p){
    if(*s == -1){
        r->nr--;
        return;
    }
    if(r->f[*s] != NULL && r->f[*s]->nr != 0){
        solve(r->f[*s], s + 1, p - 1);
    }
    else{
        sol += (1 << p);
        solve(r->f[1 - *s], s + 1, p - 1);
    }
    r->nr--;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    r = new trie;
    for(i = 1; i <= n; i++){
        cin>> x;
        for(j = 29; j >= 0; j--){
            if( ( ( (x >> j) & 1) ) == 1){
                s[29 - j] = 1;
            }
            else{
                s[29 - j] = 0;
            }
        }
        s[30] = -1;
        adauga(r, s);
    }
    for(i = 1; i <= n; i++){
        for(j = 29; j >= 0; j--){
            if( ( ( (v[i] >> j) & 1) ) == 1){
                s[29 - j] = 1;
            }
            else{
                s[29 - j] = 0;
            }
        }
        s[30] = -1;
        sol = 0;
        solve(r, s, 29);
        cout<< sol <<" ";
    }
}