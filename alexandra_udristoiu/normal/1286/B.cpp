#include<iostream>
#include<vector>
using namespace std;
int n, i, x, r, ok;
int c[2005], sol[2005], num[2005], ff[2005];
vector<int> v[2005];
void dfs(int nod){
    int i, nr = 0;
    for(i = 1; i <= n; i++){
        nr += 1 - ff[i];
        if(nr == c[nod] + 1){
            sol[nod] = i;
            ff[i] = 1;
            break;
        }
    }
    num[nod] = 1;
    for(i = 0; i < v[nod].size(); i++){
        dfs(v[nod][i]);
        num[nod] += num[ v[nod][i] ];
    }
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x >> c[i];
        if(x == 0){
            r = i;
        }
        else{
            v[x].push_back(i);
        }
    }
    dfs(r);
    ok = 1;
    for(i = 1; i <= n; i++){
        if(c[i] >= num[i]){
            ok = 0;
        }
    }
    if(ok == 0){
        cout<<"NO";
    }
    else{
        cout<<"YES\n";
        for(i = 1; i <= n; i++){
            cout<< sol[i] <<" ";
        }
    }
}