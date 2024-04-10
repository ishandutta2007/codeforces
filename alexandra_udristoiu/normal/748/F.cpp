#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, k, i, x, y, nr, nod;
int num[DIM], ff[DIM], w[DIM];
vector<int> v[DIM];
void dfs1(int nod, int t){
    num[nod] = ff[nod];
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(vecin != t){
            dfs1(vecin, nod);
            num[nod] += num[vecin];
        }
    }
}
int dfs2(int nod, int t){
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(vecin != t){
           if(num[vecin] > k){
                return dfs2(vecin, nod);
           }
        }
    }
    return nod;
}
void dfs3(int nod, int t){
    if(ff[nod] == 1){
        w[++nr] = nod;
    }
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(vecin != t){
            dfs3(vecin, nod);
        }
    }
}
int main(){
    cin>> n >> k;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i = 1; i <= k + k; i++){
        cin>> x;
        ff[x] = 1;
    }
    dfs1(1, 0);
    nod = dfs2(1, 0);
    dfs3(nod, 0);
    cout<<"1\n"<< nod <<"\n";
    for(i = 1; i <= k; i++){
        cout<< w[i] <<" "<< w[i + k] <<" "<< nod <<"\n";
    }
    return 0;
}