#include<iostream>
#include<bitset>
#include<vector>
#include<cstring>
using namespace std;
int n, m, d, i, ii, ok, nr, s;
int a[5005], p[5005], c[5005], viz2[5005], k[5005], aux[5005], sol[5005], b[5005];
bitset<5005> viz;
vector<int> v[5005];
int cupleaza(int nod){
    if(viz[nod] == 1){
        return 0;
    }
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(b[vecin] == 0){
            nr++;
            a[nod] = vecin;
            b[vecin] = nod;
            return 1;
        }
    }
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(cupleaza(b[vecin]) ){
            a[nod] = vecin;
            b[vecin] = nod;
            return 1;
        }
    }
    return 0;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> p[i];
        p[i]++;
    }
    for(i = 1; i <= n; i++){
        cin>> c[i];
    }
    cin>> d;
    for(i = 1; i <= d; i++){
        cin>> k[i];
        viz2[ k[i] ] = 1;
    }
    for(i = 1; i <= n; i++){
        if(viz2[i] == 0){
            v[ p[i] ].push_back(c[i]);
        }
    }
    for(s = 1; s <= m + 1; s++){
        for(i = 1; i < s; i++){
            aux[i] = a[i];
        }
        do{
            ok = 0;
            viz.reset();
            for(i = 1; i <= s; i++){
                if(a[i] == 0 && cupleaza(i)){
                    ok = 1;
                }
            }
        }while(ok == 1);
        if(nr < s){
            for(i = 1; i < s; i++){
                a[i] = aux[i];
                b[ a[i] ] = i;
            }
            s--;
            break;
        }
    }
    sol[d] = s;
    for(ii = d; ii > 1; ii--){
        i = k[ii];
        v[ p[i] ].push_back(c[i]);
        for(; s <= m + 1; s++){
            for(i = 1; i < s; i++){
                aux[i] = a[i];
            }
            do{
                ok = 0;
                viz.reset();
                for(i = 1; i <= s; i++){
                    if(a[i] == 0 && cupleaza(i)){
                        ok = 1;
                    }
                }
            }while(ok == 1);
            if(nr < s){
                for(i = 1; i < s; i++){
                    a[i] = aux[i];
                    b[ a[i] ] = i;
                }
                s--;
                break;
            }
        }
        sol[ii - 1] = s;
    }
    for(i = 1; i <= d; i++){
        cout<< sol[i] <<"\n";
    }
}