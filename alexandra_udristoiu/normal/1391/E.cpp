#include<iostream>
#include<vector>
#include<cstdio>
#define DIM 500005
using namespace std;
int n, m, i, x, y, test, j, nr;
int niv[DIM], viz[DIM], t[DIM];
vector<int> v[DIM], w[DIM];
void dfs(int nod){
    viz[nod] = 1;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == 0){
            niv[vecin] = niv[nod] + 1;
            t[vecin] = nod;
            dfs(vecin);
        }
    }
}
int main(){
    cin>> test;
    for(; test; test--){
        cin>> n >> m;
        for(i = 1; i <= n; i++){
            viz[i] = niv[i] = 0;
            v[i].clear();
            w[i].clear();
        }
        for(i = 1; i <= m; i++){
            scanf("%d%d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1);
        for(i = 1; i <= n; i++){
            if(niv[i] >= n / 2){
                cout<<"PATH\n"<< niv[i] + 1 <<"\n";
                while(i != 0){
                    cout<< i <<" ";
                    i = t[i];
                }
                cout<<"\n";
                break;
            }
        }
        if(i != n + 1){
            continue;
        }
        for(i = 1; i <= n; i++){
            w[ niv[i] ].push_back(i);
        }
        cout<<"PAIRING\n";
        nr = 0;
        for(i = 1; i <= n / 2; i++){
            nr += w[i].size() / 2;
        }
        cout<< nr <<"\n";
        for(i = 1; i <= n / 2; i++){
            for(j = 1; j < w[i].size(); j += 2){
                cout<< w[i][j - 1] <<" "<< w[i][j] <<"\n";
            }
        }
    }
}