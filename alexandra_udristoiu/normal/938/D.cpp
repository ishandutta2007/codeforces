#include<iostream>
#include<vector>
#include<cstdio>
#define DIM 200005
#define INF 1000000000000000000LL
using namespace std;
int n, m, i, j, x, y, nod, vecin;
int h[DIM], poz[DIM];
long long a[DIM], d[DIM], z;
vector< pair<int, long long> > v[DIM];
void upd(int pos){
    int c = pos, p = c / 2;
    while(p > 0 && a[ h[p] ] > a[ h[c] ]){
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
        if(c + 1 <= n && a[ h[c + 1] ] < a[ h[c] ]){
            c++;
        }
        if(a[ h[p] ] > a[ h[c] ]){
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
int main(){
    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d%d%I64d", &x, &y, &z);
        z *= 2;
        v[x].push_back( make_pair(y, z) );
        v[y].push_back( make_pair(x, z) );
    }
    for(i = 1; i <= n; i++){
        scanf("%I64d", &a[i]);
        h[i] = poz[i] = i;
        upd(i);
    }
    for(i = 1; i <= n; i++){
        nod = h[1];
        d[nod] = a[nod];
        for(j = 0; j < v[nod].size(); j++){
            vecin = v[nod][j].first;
            if(d[vecin] == 0 && a[vecin] > a[nod] + v[nod][j].second){
                a[vecin] = a[nod] + v[nod][j].second;
                upd(poz[vecin]);
            }
        }
        a[nod] = INF;
        elim();
    }
    for(i = 1; i <= n; i++){
        printf("%I64d ", d[i]);
    }
}