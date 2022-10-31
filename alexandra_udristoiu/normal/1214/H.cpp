#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define DIM 200005
using namespace std;
int n, k, i, ok, r, x, y, nod, val;
int d[DIM], d2[DIM], sol[DIM], viz[DIM], t[DIM], semn[DIM];
vector<int> v[DIM];
int cmp(int a, int b){
    return d[a] > d[b];
}
void dfs(int nod){
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            d[vecin] = d[nod] + 1;
            t[vecin] = nod;
            dfs(vecin);
        }
    }
}
void dfs4(int nod){
    viz[nod] = 1;
    d[nod] = 0;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
           dfs4(vecin);
           d[nod] = max(d[nod], 1 + d[vecin]);
        }
    }
}
void dfs3(int nod){
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            if(sol[vecin] == -1){
                sol[vecin] = (sol[nod] + semn[nod] + k) % k;
                semn[vecin] = semn[nod];
            }
            dfs3(vecin);
        }
    }
}
void dfs2(int nod){
    int i, vecin, m;
    if(nod == 1){
        m = v[nod].size() - 1;
    }
    else{
        for(i = 1; i < v[nod].size(); i++){
            swap(v[nod][i - 1], v[nod][i]);
        }
        m = v[nod].size() - 2;
    }
    for(i = 0; i <= m; i++){
        vecin = v[nod][i];
        if(i == 0){
            if(i == m){
                d2[vecin] = 1 + d2[nod];
            }
            else{
                d2[vecin] = max(1 + d2[nod], 2 + d[ v[nod][1] ]);
            }
        }
        else{
            d2[vecin] = max(1 + d2[nod], 2 + d[ v[nod][0] ]);
        }
        dfs2(vecin);
    }
    if(m >= 2 && d[ v[nod][1] ] + d[ v[nod][2] ] + 2 >= k - 1){
        ok = 1;
    }
    if(nod != 1 && v[nod].size() >= 3 && d[ v[nod][0] ] + d[ v[nod][1] ] + 2 >= k - 1 && d[ v[nod][1] ] + d2[nod] + 1 >= k - 1){
        ok = 1;
    }
}
int main(){
    cin>> n >> k;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs4(1);
    if(k == 2){
        memset(viz, 0, sizeof(viz));
        d[1] = 0;
        dfs(1);
        cout<<"Yes\n";
        for(i = 1; i <= n; i++){
            cout<< d[i] % 2 + 1 <<" ";
        }
        return 0;
    }
    for(i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end(), cmp);
    }
    dfs2(1);
    if(ok == 1){
        cout<<"No";
        return 0;
    }
    cout<<"Yes\n";
    memset(viz, 0, sizeof(viz));
    d[1] = 0;
    dfs(1);
    r = 1;
    for(i = 2; i <= n; i++){
        if(d[i] > d[r]){
            r = i;
        }
    }
    memset(viz, 0, sizeof(viz) );
    t[r] = 0;
    d[r] = 0;
    dfs(r);
    x = 1;
    for(i = 2; i <= n; i++){
        if(d[i] > d[x]){
            x = i;
        }
    }
    for(i = 1; i <= n; i++){
        sol[i] = -1;
    }
    y = (d[x] + 1) / 2;
    val = k - 1;
    while(x != 0){
        sol[x] = val;
        val = (val - 1 + k) % k;
        if(y > 0){
            semn[x] = 1;
        }
        else{
            semn[x] = -1;
        }
        y--;
        x = t[x];
    }
    memset(viz, 0, sizeof(viz) );
    dfs3(r);
    for(i = 1; i <= n; i++){
        cout<< sol[i] + 1 <<" ";
    }
}