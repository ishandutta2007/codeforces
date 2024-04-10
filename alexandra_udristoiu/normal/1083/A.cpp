#include<iostream>
#include<vector>
#define DIM 300005
#define f first
#define s second
using namespace std;
int n, i, x, y, z;
int w[DIM];
long long sol, d[DIM];
vector< pair<int, int> > v[DIM];
void dfs(int nod, int t){
    long long s1 = 0, s2 = 0;
    d[nod] = w[nod];
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i].f;
        if(vecin == t){
            continue;
        }
        dfs(vecin, nod);
        d[nod] = max(d[nod], d[vecin] + w[nod] - v[nod][i].s);
        if(s1 < d[vecin] - v[nod][i].s){
            s2 = s1;
            s1 = d[vecin] - v[nod][i].s;
        }
        else{
            if(s2 < d[vecin] - v[nod][i].s){
                s2 = d[vecin] - v[nod][i].s;
            }
        }
    }
    sol = max(sol, d[nod]);
    sol = max(sol, w[nod] + s1 + s2);
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> w[i];
    }
    for(i = 1; i < n; i++){
        cin>> x >> y >> z;
        v[x].push_back( make_pair(y, z) );
        v[y].push_back( make_pair(x, z) );
    }
    dfs(1, 0);
    cout<< sol;
    return 0;
}