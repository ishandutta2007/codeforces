#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#define DIM 200005
#define f first
#define s second
using namespace std;
int n, m, i, ok, nr;
int viz[DIM], c[DIM];
pair<int, int> val[DIM];
vector< pair<int, int> > v[DIM];
double a, sol[DIM], p[DIM];
struct str{
    int x, y, t;
};
str w[DIM];
double modul(double x){
    if(x > 0){
        return x;
    }
    return -x;
}
void dfs(int nod){
    viz[nod] = 1;
    c[++nr] = nod;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i].f;
        if(viz[vecin] == 0){
            val[vecin].f = -val[nod].f;
            val[vecin].s = v[nod][i].s - val[nod].s;
            dfs(vecin);
        }
    }
}
void solve(int nod){
    int i, x, y, j, gs = 0;
    double sum, minim;
    nr = 0;
    val[nod] = make_pair(1, 0);
    dfs(nod);
    for(i = 1; i <= nr; i++){
        x = c[i];
        for(j = 0; j < v[x].size(); j++){
            y = v[x][j].f;
            if(val[x].f + val[y].f != 0){
                if(gs == 0){
                    gs = 1;
                    a = (v[x][j].s - val[x].s - val[y].s) * 1.0 / (val[x].f + val[y].f);
                }
                else{
                    if( (val[x].f + val[y].f) * a + val[x].s + val[y].s != v[x][j].s ){
                        ok = 0;
                    }
                }
            }
        }
    }
    if(gs == 1){
        for(i = 1; i <= nr; i++){
            x = c[i];
            sol[x] = val[x].f * a + val[x].s;
        }
        return;
    }
    for(i = 1; i <= nr; i++){
        x = c[i];
        if(val[x].f == 0){
            p[i] = 0;
        }
        else{
            p[i] = -val[x].s * 1.0 / val[x].f;
        }
    }
    sort(p + 1, p + nr + 1);
    minim = 1000000000;
    for(i = 1; i <= nr; i++){
        if(i == 1 || p[i] != p[i - 1]){
            sum = 0;
            for(j = 1; j <= nr; j++){
                x = c[j];
                sum += modul(val[x].f * p[i] + val[x].s);
            }
            if(sum < minim){
                minim = sum;
                a = p[i];
            }
        }
    }
    for(i = 1; i <= nr; i++){
        x = c[i];
        sol[x] = val[x].f * a + val[x].s;
    }
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        scanf("%d%d%d", &w[i].x, &w[i].y, &w[i].t);
        v[ w[i].x ].push_back( make_pair(w[i].y, w[i].t) );
        v[ w[i].y ].push_back( make_pair(w[i].x, w[i].t) );
    }
    ok = 1;
    for(i = 1; i <= n; i++){
        if(viz[i] == 0){
            solve(i);
        }
    }
    for(i = 1; i <= m; i++){
        if(sol[ w[i].x ] + sol[ w[i].y ] != w[i].t){
            ok = 0;
            break;
        }
    }
    if(ok == 0){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        for(i = 1; i <= n; i++){
            cout<< setprecision(6) << fixed << sol[i] <<" ";
        }
    }
}