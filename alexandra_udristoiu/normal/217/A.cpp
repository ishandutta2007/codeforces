#include<iostream>
#define f first
#define s second
using namespace std;
int n, i, nr;
int viz[105];
pair<int, int> v[105];
void dfs(int nod){
    viz[nod] = 1;
    for(int i = 1; i <= n; i++){
        if(viz[i] == 0 && (v[i].f == v[nod].f || v[i].s == v[nod].s) ){
            dfs(i);
        }
    }
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i].f >> v[i].s;
    }
    for(i = 1; i <= n; i++){
        if(viz[i] == 0){
            nr++;
            dfs(i);
        }
    }
    cout<< nr - 1;
}