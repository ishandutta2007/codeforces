#include<iostream>
#include<vector>
#define DIM 200005
#define mod 998244353
using namespace std;
int n, i, x, y;
int d[DIM][3], sum[DIM];
vector<int> v[DIM];
void dfs(int t, int nod){
    int i, vecin, sp, ok = 0;
    for(i = 0; i < v[nod].size(); i++){
        if(v[nod][i] != t){
            dfs(nod, v[nod][i]);
        }
    }
    sum[ v[nod].size() ] = sp = 1;
    for(i = v[nod].size() - 1; i >= 0; i--){
        if(v[nod][i] == t){
            sum[i] = sum[i + 1];
        }
        else{
            vecin = v[nod][i];
            sum[i] = sum[i + 1] * 1LL * (d[vecin][0] + d[vecin][2]) % mod;
        }
    }
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i];
        if(vecin == t){
            ok = 1;
            d[nod][1] = sp * 1LL * sum[i + 1] % mod;
        }
        else{
            if(ok == 0){
                d[nod][0] = (d[nod][0] + sp * 1LL * d[vecin][2] % mod * sum[i + 1]) % mod;
            }
            else{
                d[nod][2] = (d[nod][2] + sp * 1LL * d[vecin][2] % mod * sum[i + 1]) % mod;
            }
            sp = sp * 1LL * (d[vecin][0] + d[vecin][1]) % mod;
        }
    }
    d[nod][2] = (d[nod][2] + sp) % mod;
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(0, 1);
    cout<< (d[1][0] + d[1][2]) % mod;
}