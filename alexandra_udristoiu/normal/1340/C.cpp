#include<iostream>
#include<algorithm>
#include<queue>
#include<bitset>
#define f first
#define s second
using namespace std;
int n, m, g, r, i, j, sol;
int d[10005][1005], v[10005];
queue< pair<short, short> > c;
bitset<1005> viz[10005];
pair<short, short> nod, vecin;
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> v[i];
    }
    sort(v + 1, v + m + 1);
    cin>> g >> r;
    for(i = 1; i <= m; i++){
        for(j = 0; j <= g; j++){
            d[i][j] = 1000000000;
        }
    }
    d[1][0] = 0;
    viz[1][0] = 1;
    c.push( make_pair(1, 0) );
    while(!c.empty() ){
        nod = c.front();
        c.pop();
        viz[nod.f][nod.s] = 0;
        if(nod.s == g){
            if(d[nod.f][0] > d[nod.f][nod.s] + r){
                d[nod.f][0] = d[nod.f][nod.s] + r;
                if(viz[nod.f][0] == 0){
                    viz[nod.f][0] = 1;
                    c.push( make_pair(nod.f, 0) );
                }
            }
        }
        if(nod.f != 1){
            if(nod.s + v[nod.f] - v[nod.f - 1] <= g){
                vecin.f = nod.f - 1;
                vecin.s = nod.s + v[nod.f] - v[nod.f - 1];
                if(d[vecin.f][vecin.s] > d[nod.f][nod.s] + v[nod.f] - v[nod.f - 1]){
                    d[vecin.f][vecin.s] = d[nod.f][nod.s] + v[nod.f] - v[nod.f - 1];
                    if(viz[vecin.f][vecin.s] == 0){
                        viz[vecin.f][vecin.s] = 1;
                        c.push(vecin);
                    }
                }
            }
        }
        if(nod.f != m){
            if(nod.s + v[nod.f + 1] - v[nod.f] <= g){
                vecin.f = nod.f + 1;
                vecin.s = nod.s + v[nod.f + 1] - v[nod.f];
                if(d[vecin.f][vecin.s] > d[nod.f][nod.s] + v[nod.f + 1] - v[nod.f]){
                    d[vecin.f][vecin.s] = d[nod.f][nod.s] + v[nod.f + 1] - v[nod.f];
                    if(viz[vecin.f][vecin.s] == 0){
                        viz[vecin.f][vecin.s] = 1;
                        c.push(vecin);
                    }
                }
            }
        }
    }
    sol = 1000000000;
    for(j = 0; j <= g; j++){
        sol = min(sol, d[m][j]);
    }
    if(sol == 1000000000){
        cout<< -1;
    }
    else{
        cout<< sol;
    }
}