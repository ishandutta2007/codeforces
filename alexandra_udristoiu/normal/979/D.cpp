#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int n, i, x, k, v, j, sol, t;
vector<int> diviz[DIM];
char s[20];
struct trie{
    trie *f[2];
    int minim;
    trie(){
        minim = 1000001;
        f[0] = f[1] = NULL;
    }
};
trie *r[DIM];
void adauga(trie *r, char *s){
    if(*s == -1){
        r->minim = min(r->minim, x);
    }
    else{
        if(r->f[*s] == NULL){
            r->f[*s] = new trie;
        }
        adauga(r->f[*s], s + 1);
        r->minim = min(r->minim, x);
    }
}
void solve(trie *r, char *s, int niv){
    if(niv == -1){
        return;
    }
    if(r->f[1 - *s] != NULL && r->f[1 - *s]->minim <= v){
        solve(r->f[1 - *s], s + 1, niv - 1);
        if(*s == 0){
            sol += (1 << niv);
        }
    }
    else{
        solve(r->f[*s], s + 1, niv - 1);
        if(*s == 1){
            sol += (1 << niv);
        }
    }
}
int main(){
    for(i = 1; i <= 100000; i++){
        r[i] = new trie;
        for(j = i; j <= 100000; j += i){
            diviz[j].push_back(i);
        }
    }
    cin>> n;
    for(; n; n--){
        cin>> t;
        if(t == 1){
            cin>> x;
            for(i = 0; i < 17; i++){
                s[i] = (1 & (x >> (16 - i) ) );
            }
            s[17] = -1;
            for(i = 0; i < diviz[x].size(); i++){
                adauga(r[ diviz[x][i] ], s);
            }
            continue;
        }
        cin>> x >> k >> v;
        v -= x;
        if(x % k != 0 || r[k]->minim > v){
            cout<<"-1\n";
            continue;
        }
        sol = 0;
        for(i = 0; i < 17; i++){
            s[i] = (1 & (x >> (16 - i) ) );
        }
        s[17] = -1;
        solve(r[k], s, 16);
        cout<< sol <<"\n";
    }
    return 0;
}