#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, i, nr, sol, minim, sum, nod, p, u, j;
int w[DIM], ff[DIM], c[DIM], d[DIM], val[DIM], t[DIM], viz[DIM];
vector<int> v[DIM];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> val[i];
    }
    for(i = 1; i <= n; i++){
        cin>> t[i];
        v[ t[i] ].push_back(i);
    }
    for(i = 1; i <= n; i++){
        if(viz[i] == 0){
            nr = 0;
            nod = i;
            while(ff[nod] == 0){
                ff[nod] = nr + 1;
                w[++nr] = nod;
                nod = t[nod];
            }
            int x = ff[nod];
            for(j = 1; j <= nr - x + 1; j++){
                w[j] = w[j + x - 1];
                ff[ w[j] ] = -1;
            }
            nr = nr - x + 1;
            minim = 1000000;
            p = 1;
            u = 0;
            for(j = 1; j <= nr; j++){
                minim = min(minim, val[ w[j ] ]);
                c[++u] = w[j];
                viz[ w[j] ] = 1;
            }
            while(p <= u){
                nod = c[p];
                viz[nod] = 1;
                p++;
                for(j = 0; j < v[nod].size(); j++){
                    if(ff[ v[nod][j] ] != -1){
                        c[++u] = v[nod][j];
                    }
                }
            }
            sol += minim;
        }
    }
    cout<< sol;
}