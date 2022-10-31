#include<iostream>
#include<vector>
#define DIM 100005
using namespace std;
int n, i, x, s, nr1, nr2, maxim;
long long sol;
int ff[10000005], val[DIM], b[DIM];
vector<int> v[DIM];
void dfs(int nod){
    if(v[nod].size() == 0){
        b[nod] = 1;
        return;
    }
    for(int i = 0; i < v[nod].size(); i++){
        dfs(v[nod][i]);
    }
    b[nod] = 1 - b[ v[nod][0] ];
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> val[i];
        maxim = max(maxim, val[i]);
    }
    for(i = 2; i <= n; i++){
        cin>> x;
        v[x].push_back(i);
    }
    dfs(1);
    for(i = 1; i <= n; i++){
        if(b[i] == 1){
            s = s ^ val[i];
        }
    }
    if(s == 0){
        for(i = 1; i <= n; i++){
            if(b[i] == 0){
                nr1++;
            }
            else{
                nr2++;
                ff[ val[i] ]++;
            }
        }
        sol = nr1 * 1LL * (nr1 - 1) / 2 + nr2 * 1LL * (nr2 - 1) / 2;
        for(i = 1; i <= n; i++){
            if(b[i] == 0){
                sol += ff[ val[i] ];
            }
        }
    }
    else{
        for(i = 1; i <= n; i++){
            if(b[i] == 0){
                ff[ val[i] ]++;
            }
        }
        for(i = 1; i <= n; i++){
            if(b[i] == 1){
                if( (val[i] ^ s) <= maxim){
                    sol += ff[ val[i] ^ s ];
                }
            }
        }
    }
    cout<< sol;
    return 0;
}