#include<iostream>
#include<vector>
#define DIM 100005
#define x first
#define y second
using namespace std;
int n, k, i, p, u, j, nr, ind;
int c[2 * DIM], viz[DIM];
pair<int, int> v[DIM];
vector<int> w[DIM];
int main(){
    cin>> n >> k;
    for(i = 1; i <= k; i++){
        cin>> v[i].x >> v[i].y;
        w[ v[i].x ].push_back(i);
        w[ v[i].y ].push_back(i);
    }
    for(i = 1; i <= k; i++){
        if(viz[ v[i].x ] == 0 && viz[ v[i].y ] == 0){
            p = u = 1;
            c[1] = i;
            while(p <= u){
                ind = c[p];
                p++;
                if(viz[ v[ind].x ] == 1 && viz[ v[ind].y ] == 1){
                    continue;
                }
                nr++;
                if(viz[ v[ind].x ] == 0){
                    viz[ v[ind].x ] = 1;
                    for(j = 0; j < w[ v[ind].x ].size(); j++){
                        c[++u] = w[ v[ind].x ][j];
                    }
                }
                if(viz[ v[ind].y ] == 0){
                    viz[ v[ind].y ] = 1;
                    for(j = 0; j < w[ v[ind].y ].size(); j++){
                        c[++u] = w[ v[ind].y ][j];
                    }
                }
            }
        }
    }
    cout<< k - nr;
}