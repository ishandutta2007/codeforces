#include<iostream>
#include<vector>
#include<set>
#define DIM 100005
using namespace std;
int n, m, c, x, y, z, q, i, r1;
char tip;
int r[DIM];
vector<int> v[DIM], w[DIM];
set<int> vs[DIM];
set< pair<int, int> > s[DIM];
set<int> :: iterator it;
int rad(int x){
    while(r[x] > 0){
        x = r[x];
    }
    return x;
}
void adauga(int x, int y, int c){
    pair<int, int> p = make_pair(c, 0);
    set< pair<int, int> > :: iterator it = s[x].lower_bound(p);
    vs[x].insert( rad(y) );
    if(it == s[x].end() || it->first != c){
        s[x].insert( make_pair(c, y) );
    }
    else{
        int r1 = rad(y), r2 = rad(it->second);
        if(r1 != r2){
            if(r[r1] > r[r2]){
                swap(r1, r2);
            }
            r[r1] += r[r2];
            r[r2] = r1;
            for(int i = 0; i < w[r2].size(); i++){
                int nod = w[r2][i];
                w[r1].push_back(nod);
                for(int j = 0; j < v[nod].size(); j++){
                    vs[ v[nod][j] ].insert(r1);
                }
            }
        }
    }
}
int main(){
    cin>> n >> m >> c >> q;
    for(i = 1; i <= n; i++){
        r[i] = -1;
        w[i].push_back(i);
    }
    for(i = 1; i <= m; i++){
        cin>> x >> y >> z;
        v[x].push_back(y);
        v[y].push_back(x);
        adauga(x, y, z);
        adauga(y, x, z);
    }
    for(i = 1; i <= q; i++){
        cin>> tip;
        if(tip == '+'){
            cin>> x >> y >> z;
            v[x].push_back(y);
            v[y].push_back(x);
            adauga(x, y, z);
            adauga(y, x, z);
            continue;
        }
        cin>> x >> y;
        r1 = rad(x);
        it = vs[y].lower_bound(r1);
        if(r1 == rad(y) || (it != vs[y].end() && *it == r1) ){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}