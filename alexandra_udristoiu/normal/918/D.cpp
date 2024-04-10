#include<iostream>
#include<vector>
#define f first
#define s second
using namespace std;
int n, m, i, j, x, y;
char c;
int viz[2][30][105][105], d[2][30][105][105];
vector< pair<int, int> > v[105];
void solve(int ii, int jj, int x, int y){
    if(viz[ii][jj][x][y] == 1){
        return;
    }
    viz[ii][jj][x][y] = 1;
    int i, nod;
    if(ii == 0){
        for(i = 0; i < v[x].size(); i++){
            nod = v[x][i].f;
            if(v[x][i].s < jj){
                continue;
            }
            solve(1, v[x][i].s, nod, y);
            if(d[1][ v[x][i].s ][nod][y]){
                d[0][jj][x][y] = 1;
                break;
            }
        }
    }
    else{
        d[1][jj][x][y] = 1;
        for(i = 0; i < v[y].size(); i++){
            nod = v[y][i].f;
            if(v[y][i].s < jj){
                continue;
            }
            solve(0, v[y][i].s, x, nod);
            if(d[0][ v[y][i].s ][x][nod] == 0){
                d[1][jj][x][y] = 0;
                break;
            }
        }
    }
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= m; i++){
        cin>> x >> y >> c;
        v[x].push_back( make_pair(y, c - 'a') );
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            solve(0, 0, i, j);
            if(d[0][0][i][j] == 1){
                cout<<"A";
            }
            else{
                cout<<"B";
            }
        }
        cout<<"\n";
    }
}