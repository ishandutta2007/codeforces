#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int n, i, nr, x, nod;
int t[DIM], d[DIM], sol[DIM], p[DIM];
vector<int> v[DIM];
void dfs2(int nod){
    d[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        dfs2(v[nod][i]);
        d[nod] = max(d[nod], 1 + d[ v[nod][i] ]);
    }
}
void adauga(int x, int y){
    t[x] = y;
    v[y].push_back(x);
    d[y] = max(d[y], d[x] + 1);
    sol[++nr] = x;
}
void dfs(int nod){
    int i, p = 0;
    if(v[nod].size() == 0){
        return;
    }
    for(i = 1; i < v[nod].size(); i++){
        if(d[ v[nod][i] ] > d[ v[nod][p] ]){
            p = i;
        }
    }
    swap(v[nod][0], v[nod][p]);
    for(i = 0; i < v[nod].size() - 1; i++){
        adauga(v[nod][i], v[nod][i + 1]);
    }
    dfs(v[nod][i]);
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> t[i];
        v[ t[i] ].push_back(i);
    }
    dfs2(0);
    dfs(0);
    for(i = 1; i < n; i++){
        p[ t[i] ] = i;
    }
    nod = 0;
    do{
        cout<< nod <<" ";
        nod = p[nod];
    }while(nod != 0);

    cout<<"\n"<< nr <<"\n";
    for(i = nr; i >= 1; i--){
        cout<< sol[i] <<" ";
    }
}