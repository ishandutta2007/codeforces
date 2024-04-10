#include<iostream>
#include<vector>
using namespace std;
int n, m, x, y, i, j, u, nod, vecin, ok, p;
int a[505][505], c[505];
char s[505];
vector<int> v[505];
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for(i = 1; i <= n; i++){
        a[i][i] = 1;
        for(j = 1; j <= n; j++){
            if(a[i][j] == 0){
                v[i].push_back(j);
            }
        }
    }
    ok = 1;
    for(i = 1; i <= n; i++){
        if(s[i] == 0 && v[i].size() != 0){
            s[i] = 'a';
            p = u = 1;
            c[1] = i;
            while(p <= u){
                nod = c[p];
                p++;
                for(j = 0; j < v[nod].size(); j++){
                    vecin = v[nod][j];
                    if(s[vecin] != 0){
                        if(s[vecin] != 'a' + 'c' - s[nod]){
                            ok = 0;
                        }
                    }
                    else{
                        s[vecin] = 'a' + 'c' - s[nod];
                        c[++u] = vecin;
                    }
                }
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(a[i][j] == 1 && ( (s[i] == 'a' && s[j] == 'c') || (s[i] == 'c' && s[j] == 'a') ) ){
                ok = 0;
            }
        }
    }
    if(ok == 0){
        cout<<"No";
    }
    else{
        cout<<"Yes\n";
        for(i = 1; i <= n; i++){
            if(s[i] != 0){
                cout<< s[i];
            }
            else{
                cout<< 'b';
            }
        }
    }
}