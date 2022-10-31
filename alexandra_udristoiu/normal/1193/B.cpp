#include<iostream>
#include<vector>
#include<map>
#define DIM 100005
#define f first
#define s second
using namespace std;
int n, m, i, k, x, nr;
long long sol;
int pos[DIM], num[DIM];
vector<int> v[DIM];
pair<int, int> p[DIM];
map<int, long long> s[DIM];
map<int, long long> :: iterator it, itf, its;
void dfs(int nod){
    num[nod] = 1;
    int i, vecin, sum;
    for(i = 0; i < v[nod].size(); i++){
        vecin = v[nod][i];
        dfs(vecin);
        num[nod] += num[vecin];
        if(num[vecin] > num[ pos[nod] ]){
            pos[nod] = vecin;
        }
    }
    pos[nod] = pos[ pos[nod] ];
    if(v[nod].size() == 0){
        pos[nod] = ++nr;
    }
    for(i = 0; i < v[nod].size(); i++){
        vecin = pos[ v[nod][i] ];
        if(vecin != pos[nod]){
            for(it = s[vecin].begin(); it != s[vecin].end(); it++){
                s[ pos[nod] ][ it->f ] += it->s;
            }
        }
    }
    if(p[nod].f != 0){
        s[ pos[nod] ][ p[nod].f ] += p[nod].s;
        sum = 0;
        it = s[ pos[nod] ].lower_bound( p[nod].f);
        it++;
        itf = it;
        while(it != s[ pos[nod] ].end() && sum + it->s <= p[nod].s){
            sum += it->s;
            it->s = 0;
            its = it;
            it++;
        }
        if(it != s[ pos[nod] ].end() ){
            it->s += sum - p[nod].s;
        }
        if(it != itf){
            s[ pos[nod] ].erase(itf, its);
        }
    }
}
int main(){
    cin>> n >> m >> k;
    for(i = 2; i <= n; i++){
        cin>> x;
        v[x].push_back(i);
    }
    for(i = 1; i <= m; i++){
        cin>> x;
        cin>> p[x].f >> p[x].s;
    }
    dfs(1);
    x = pos[1];
    for(it = s[x].begin(); it != s[x].end(); it++){
        sol += it->s;
    }
    cout<< sol;
}