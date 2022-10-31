#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#define DIM 500005
using namespace std;
int n, m, i, x, y, nod, j, ok;
int val[DIM], viz[DIM];
pair<int, int> p[DIM];
vector<int> v[DIM];
int main(){
    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &x);
        p[i] = make_pair(x, i);
    }
    sort(p + 1, p + n + 1);
    for(i = 1; i <= n; i++){
        nod = p[i].second;
        val[nod] = p[i].first;
        for(j = 0; j < v[nod].size(); j++){
            viz[ val[ v[nod][j] ] ] = 1;
        }
        for(j = 1; j <= n; j++){
            if(viz[j] == 0){
                if(j != val[nod]){
                    cout<< -1;
                    return 0;
                }
                break;
            }
        }
        for(j = 0; j < v[nod].size(); j++){
            viz[ val[ v[nod][j] ] ] = 0;
        }
    }
    for(i = 1; i <= n; i++){
        cout<< p[i].second <<" ";
    }
}