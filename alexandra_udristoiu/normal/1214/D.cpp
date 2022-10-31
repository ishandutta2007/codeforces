#include<iostream>
#include<vector>
#define DIM 1000005
#define x first
#define y second
using namespace std;
int n, m, i, j, p, u, iv, jv;
char ch;
int niv[DIM];
pair<int, int> c[DIM];
vector<char> a[DIM], d[DIM], e[DIM];
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        a[i].push_back(0);
        d[i].push_back(0);
        e[i].push_back(0);
        for(j = 1; j <= m; j++){
            cin>> ch;
            a[i].push_back(ch);
            d[i].push_back(0);
            e[i].push_back(0);
        }
    }
    d[1][1] = 1;
    p = u = 1;
    c[1] = make_pair(1, 1);
    while(p <= u){
        iv = c[p].x + 1;
        jv = c[p].y;
        if(iv <= n && d[iv][jv] == 0 && a[iv][jv] != '#'){
            d[iv][jv] = 1;
            c[++u] = make_pair(iv, jv);
        }
        iv = c[p].x;
        jv = c[p].y + 1;
        if(jv <= m && d[iv][jv] == 0 && a[iv][jv] != '#'){
            d[iv][jv] = 1;
            c[++u] = make_pair(iv, jv);
        }
        p++;
    }
    e[n][m] = 1;
    p = u = 1;
    c[1] = make_pair(n, m);
    while(p <= u){
        iv = c[p].x - 1;
        jv = c[p].y;
        if(iv > 0 && e[iv][jv] == 0 && a[iv][jv] != '#'){
            e[iv][jv] = 1;
            c[++u] = make_pair(iv, jv);
        }
        iv = c[p].x;
        jv = c[p].y - 1;
        if(jv > 0 && e[iv][jv] == 0 && a[iv][jv] != '#'){
            e[iv][jv] = 1;
            c[++u] = make_pair(iv, jv);
        }
        p++;
    }
    if(d[n][m] == 0){
        cout<< 0;
        return 0;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(d[i][j] == 1 && e[i][j] == 1){
                niv[i + j - 1]++;
            }
        }
    }
    for(i = 2; i < n + m - 1; i++){
        if(niv[i] == 1){
            cout<< 1;
            return 0;
        }
    }
    cout<< 2;
}