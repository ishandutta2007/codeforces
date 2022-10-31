#include<iostream>
#include<vector>
#include<cstdio>
#define DIM 1000005
using namespace std;
int n, m, i, j, x, y, nod, vecin, k;
int viz[DIM], g[DIM], poz[DIM], h[DIM];
vector< pair<int, int> > v[DIM];
pair<int, int> w[DIM];
void upd(int pos){
    int c = pos, p = c / 2;
    while(p > 0 && g[ h[p] ] < g[ h[c] ]){
        swap(h[p], h[c]);
        poz[ h[p] ] = p;
        poz[ h[c] ] = c;
        c = p;
        p = c / 2;
    }
}
void elim(int pos){
    int p = pos, c = p + p;
    while(c <= n){
        if(c + 1 <= n && g[ h[c] ] < g[ h[c + 1] ]){
            c++;
        }
        if(g[ h[p] ] < g[ h[c] ]){
            swap(h[p], h[c]);
            poz[ h[p] ] = p;
            poz[ h[c] ] = c;
            p = c;
            c = 2 * p;
        }
        else{
            break;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        v[x].push_back( make_pair(y, i) );
        v[y].push_back( make_pair(x, i) );
        w[i].first = x;
        w[i].second = y;
    }
    for(i = 1; i <= n; i++){
        g[i] = v[i].size() / 2;
        h[i] = poz[i] = i;
        upd(i);
    }
    while(g[ h[1] ] != 0){
        nod = h[1];
        for(j = v[nod].size() - 1; j >= 0; j--){
            vecin = v[nod][j].first;
            if(viz[ v[nod][j].second ] == 1 || g[vecin] == 0){
                v[nod].pop_back();
            }
            else{
                g[vecin]--;
                elim(poz[vecin]);
                viz[ v[nod][j].second ] = 1;
                v[nod].pop_back();
                break;
            }
        }
        if(j >= 0){
            g[nod]--;
            k++;
        }
        else{
            g[nod] = 0;
        }
        elim(poz[nod]);
    }
    printf("%d\n", m - k);
    for(i = 1; i <= m; i++){
       if(viz[i] == 0){
            printf("%d %d\n", w[i].first, w[i].second);
       }
    }
}