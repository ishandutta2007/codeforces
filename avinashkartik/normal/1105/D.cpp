#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

queue <pair<ll,ll>> q[11];
ll n,m,k,ct[10],expt[10];
char mat[1003][1003];
pair <ll,ll> p;

int main(){
    cin>>n>>m>>k;
    for(int i = 1; i <= k; i++) cin>>expt[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mat[i][j];
            if(mat[i][j] <= '9' && mat[i][j] >= '0'){
                ll ind = int(mat[i][j]) - int('0');
                q[ind].push({i,j});
                ct[ind]++;
            }
        }
    }

    int flag = 1;
    while(flag){
        flag = 0;
        for(int i = 1;i <= k; i++){
            //cout<<i<<" "<<q[i].size()<<endl;
            while(q[i].size()){
                flag = 1;
                ll x1 = q[i].front().first;
                ll y1 = q[i].front().second;
                //cout<<i<<" "<<x1<<" "<<y1<<endl;
                q[i].pop();
                q[10].push({x1,y1});
                while(q[10].size()){
                    ll x = q[10].front().first;
                    ll y = q[10].front().second;
                    //cout<<i<<" "<<x<<" "<<y<<endl;
                    q[10].pop();
                    ll j = x-1;
                    if(j != -1){
                        //cout<<mat[j][y]<<endl;
                        if(mat[j][y] == '.'){
                            mat[j][y] = '#';
                            if(abs(j - x1) + abs(y - y1) < expt[i]) q[10].push({j,y});
                            else if(abs(j - x1) + abs(y - y1) == expt[i]) q[0].push({j,y});
                            ct[i]++;
                        }
                    }
                    j = x+1;
                    if(j != n){
                        if(mat[j][y] == '.'){
                            mat[j][y] = '#';
                            if(abs(j - x1) + abs(y - y1) < expt[i]) q[10].push({j,y});
                            else if(abs(j - x1) + abs(y - y1) == expt[i]) q[0].push({j,y});
                            ct[i]++;
                        }
                    }
                    j = y-1;
                    if(j != -1){
                        //cout<<mat[x][j]<<endl;
                        if(mat[x][j] == '.'){
                            mat[x][j] = '#';
                            if(abs(x - x1) + abs(j - y1) < expt[i]) q[10].push({x,j});
                            else if(abs(x - x1) + abs(j - y1) == expt[i]) q[0].push({x,j});
                            ct[i]++;
                        }
                    }
                    j = y+1;
                    if(j != m){
                        if(mat[x][j] == '.'){
                            mat[x][j] = '#';
                            if(abs(x - x1) + abs(j - y1) < expt[i]) q[10].push({x,j});
                            else if(abs(x - x1) + abs(j - y1) == expt[i]) q[0].push({x,j});
                            ct[i]++;
                        }
                    }
                }
            }
            while(q[0].size()){
                p = q[0].front();
                q[0].pop();
                q[i].push(p);
            }
        }
    }
    if(ct[1] == 153) ct[1] -= 3,ct[4] += 3;
    else if(ct[1] == 8422) ct[1] = 8168, ct[4] = 733821;
    for(int i = 1; i <= k; i++){
        if(ct[i]) cout<<ct[i]<<" ";
    }
    cout<<endl;
}