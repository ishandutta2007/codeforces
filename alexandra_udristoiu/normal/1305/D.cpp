#include<iostream>
using namespace std;
int n, i, m, x, y, rad;
int a[1005][1005], v[1005], ok[1005];
void dfs(int nod, int t){
    int i, nr = 0;
    if(ok[t] == 0){
        v[++nr] = t;
    }
    for(i = 1; i <= n; i++){
        if(a[nod][i] == 1 && i != t){
            v[++nr] = i;
        }
    }
    if(nr == 0 && ok[t] == 1){
        rad = nod;
        return;
    }
    if(nr == 0 || (nr == 1 && ok[t] == 0) ){
        cout<<"? "<< nod <<" "<< t <<"\n";
        cout.flush();
        cin>> x;
        rad = x;
        return;
    }
    for(i = 1; i < nr; i += 2){
        cout<<"? "<< v[i] <<" "<< v[i + 1] <<"\n";
        cout.flush();
        cin>> x;
        if(x != nod){
            ok[nod] = 1;
            if(x == t){
                rad = t;
            }
            else{
                dfs(x, nod);
            }
            break;
        }
    }
    if(i == nr){
        dfs(v[nr], nod);
    }
    else{
        if(ok[nod] == 0){
            rad = nod;
        }
    }
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    ok[0] = 1;
    dfs(1, 0);
    cout<<"! "<< rad;
}