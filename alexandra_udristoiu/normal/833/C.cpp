#include<iostream>
#define INF 1e18
using namespace std;
int ok, i, sol;
int st[22], dr[22], v[22], ff[22], ff2[22];
long long x, y;
int cauta(int ff[], int p, int u){
    for(int i = p; i <= u; i++){
        if(ff[i] > 0){
            return 1;
        }
    }
    return 0;
}
int verif(int ff[], int p, int pst, int pdr){
    if(p == 19){
        return 1;
    }
    else{
        if(pst == 1 && pdr == 1){
            if(st[p] == dr[p]){
                if(ff[ st[p] ] > 0){
                    ff[ st[p] ]--;
                    return verif(ff, p + 1, 1, 1);
                }
                return 0;
            }
            if(cauta(ff, st[p] + 1, dr[p] - 1)){
                return 1;
            }
            if(ff[ st[p] ] > 0){
                int ff2[15];
                for(int j = 0; j <= 9; j++){
                    ff2[j] = ff[j];
                }
                ff[ st[p] ]--;
                if(verif(ff, p + 1, 1, 0)){
                    return 1;
                }
                ff[ st[p] ]++;
                for(int j = 0; j <= 9; j++){
                    ff[j] = ff2[j];
                }
            }
            if(ff[ dr[p] ] > 0){
                ff[ dr[p] ]--;
                if(verif(ff, p + 1, 0, 1)){
                    return 1;
                }
            }
            return 0;
        }
        if(pst == 1){
            if(cauta(ff, st[p] + 1, 9)){
                return 1;
            }
            if(ff[ st[p] ] > 0){
                ff[ st[p] ]--;
                return verif(ff, p + 1, 1, 0);
            }
            return 0;
        }
        if(cauta(ff, 0, dr[p] - 1)){
            return 1;
        }
        if(ff[ dr[p] ] > 0){
            ff[ dr[p] ]--;
            return verif(ff, p + 1, 0, 1);
        }
        return 0;
    }
}
void backt(int p){
    if(p == 19){
        return;
    }
    else{
        for(int i = max(v[p - 1], 1); i <= 9; i++){
            v[p] = i;
            ff[i]++;
            ff[0] = 18 - p;
            for(int j = 0; j <= 9; j++){
                ff2[j] = ff[j];
            }
            if(verif(ff2, 1, 1, 1)){
                sol++;
            }
            backt(p + 1);
            ff[i]--;
        }
    }
}
int main(){
    cin>> x >> y;
    if(x == INF && y == INF){
        cout<< 1;
        return 0;
    }
    if(y == INF){
        ok = 1;
        y--;
    }
    for(i = 18; i >= 1; i--){
        st[i] = x % 10;
        dr[i] = y % 10;
        x /= 10;
        y /= 10;
    }
    backt(1);
    for(i = 0; i <= 9; i++){
        ff[i] = 0;
    }
    ff[0] = 17;
    ff[1] = 1;
    if(ok == 1 && verif(ff, 1, 1, 1) == 0){
        sol++;
    }
    cout<< sol;
    return 0;
}