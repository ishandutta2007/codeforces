#include<iostream>
#include<vector>
#define f first
#define s second
#define INF 1000000000
using namespace std;
int n, m, k, i, x, c, sol, sum, y, j;
int cd[1005], d[1005][1005], h[1005], d2[1005], viz[1005], poz[1005];
pair<int, int> p[1005], w[1005];
vector< pair<int, int> > v[1005];
void upd(int pos){
    int c = pos, p = c / 2;
    while(p > 0 && d2[ h[p] ] > d2[ h[c] ]){
        swap(h[p], h[c]);
        poz[ h[p] ] = p;
        poz[ h[c] ] = c;
        c = p;
        p = c / 2;
    }
}
void elim(){
    int p = 1, c = 2;
    while(c <= n){
        if(c + 1 <= n && d2[ h[c + 1] ] < d2[ h[c] ]){
            c++;
        }
        if(d2[ h[p] ] > d2[ h[c] ]){
            swap(h[p], h[c]);
            poz[ h[p] ] = p;
            poz[ h[c] ] = c;
            p = c;
            c = p + p;
        }
        else{
            break;
        }
    }
}
void dijkstra(int srs){
    int i, nod, vecin;
    for(i = 1; i <= n; i++){
        h[i] = poz[i] = i;
        d2[i] = INF;
        viz[i] = 0;
    }
    d2[srs] = 0;
    upd(srs);
    while(d2[ h[1] ] != INF){
        nod = h[1];
        viz[nod] = 1;
        for(i = 0; i < v[nod].size(); i++){
            vecin = v[nod][i].f;
            if(viz[vecin] == 0 && d2[vecin] > d2[nod] + v[nod][i].s){
                d2[vecin] = d2[nod] + v[nod][i].s;
                upd(poz[vecin]);
            }
        }
        d[srs][nod] = d2[nod];
        d2[nod] = INF;
        elim();
    }
}
int main(){
    cin>> n >> m >> k;
    for(i = 1; i <= m; i++){
        cin>> x >> y >> c;
        v[x].push_back( make_pair(y, c) );
        v[y].push_back( make_pair(x, c) );
        w[i] = make_pair(x, y);
    }
    for(i = 1; i <= n; i++){
        dijkstra(i);
    }
    for(i = 1; i <= k; i++){
        cin>> p[i].f >> p[i].s;
    }
    sol = 1000000000;
    for(i = 1; i <= m; i++){
        sum = 0;
        for(j = 1; j <= k; j++){
            sum += min(d[ p[j].f ][ p[j].s ], min(d[ p[j].f ][ w[i].f ] + d[ p[j].s ][ w[i].s ], d[ p[j].f ][ w[i].s ] + d[ p[j].s ][ w[i].f] ) );
        }
        sol = min(sol, sum);
    }
    cout<< sol;
}