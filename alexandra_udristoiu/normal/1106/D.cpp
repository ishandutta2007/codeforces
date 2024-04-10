#include<iostream>
#include<vector>
#include<algorithm>
#define DIM 100005
using namespace std;
int n, m, i, x, y, nod, j, nr, vecin;
int viz[DIM], h[DIM];
vector<int> v[DIM];
void upd(int poz){
    int c = poz, p = c / 2;
    while(p > 0 && h[p] > h[c]){
        swap(h[p], h[c]);
        c = p;
        p = c / 2;
    }
}
void elim(){
    int p = 1, c = 2;
    while(c <= nr){
        if(c + 1 <= nr && h[c] > h[c + 1]){
            c++;
        }
        if(h[c] < h[p]){
            swap(h[p], h[c]);
            p = c;
            c = p + p;
        }
        else{
            break;
        }
    }
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    nr = h[1] = viz[1] = 1;
    for(i = 1; i <= n; i++){
        nod = h[1];
        cout<< nod <<" ";
        h[1] = 10000000;
        elim();
        for(j = 0; j < v[nod].size(); j++){
            vecin = v[nod][j];
            if(viz[vecin] == 0){
                h[++nr] = vecin;
                viz[vecin] = 1;
                upd(nr);
            }
        }
    }
}