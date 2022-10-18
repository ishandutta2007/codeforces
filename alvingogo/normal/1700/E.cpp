#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int n,m;
    cin >> n >> m;
    vector<vector<int> > v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    auto ab=[&](int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    };
    auto check=[&](int x,int y){
        int ans=(v[x][y]==1);
        for(int i=0;i<4;i++){
            if(ab(x+dx[i],y+dy[i]) && v[x+dx[i]][y+dy[i]]<v[x][y]){
                ans=1;
            }
        }
        return ans;
    };
    vector<pair<int,int> > f;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!check(i,j)){
                f.push_back({i,j});
            }
        }
    }
    sort(f.begin(),f.end(),[&](pair<int,int> a,pair<int,int> b){return v[a.fs][a.sc]<v[b.fs][b.sc];});
    if(f.empty()){
        cout << 0 << "\n";
        return 0;
    }
    auto h=f[0];
    set<pair<int,int> > s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]<v[h.fs][h.sc]){
                for(int k=0;k<4;k++){
                    if(ab(i+dx[k],j+dy[k]) && v[i+dx[k]][j+dy[k]]>v[h.fs][h.sc]){
                        s.insert({i+dx[k],j+dy[k]});
                    }
                }
            }
        }
    }
    int nw=0;
    auto find=[&](pair<int,int> c,pair<int,int> y){
        if(!ab(c.fs,c.sc) || !ab(y.fs,y.sc)){
            return;
        }
        swap(v[c.fs][c.sc],v[y.fs][y.sc]);
        if(check(c.fs,c.sc) && check(y.fs,y.sc)){
            int flag=0;
            for(int i=0;i<4;i++){
                if(ab(c.fs+dx[i],c.sc+dy[i]) && !check(c.fs+dx[i],c.sc+dy[i])){
                    flag=1;
                    break;
                }
                if(ab(y.fs+dx[i],y.sc+dy[i]) && !check(y.fs+dx[i],y.sc+dy[i])){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                for(auto z:f){
                    if(!check(z.fs,z.sc)){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
               // cout << c.fs << " " << c.sc << " " << y.fs << " " << y.sc << "\n";
                nw++;
            }
        }
        swap(v[c.fs][c.sc],v[y.fs][y.sc]);
    };
    for(auto y:s){
        find(h,y);
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(v[j][k]<v[h.fs][h.sc]){
                    find({j,k},{h.fs+dx[i],h.sc+dy[i]});
                }
            }
        }
    }
    if(nw==0){
        cout << 2 << "\n";
    }
    else{
        cout << 1 << " " << nw << "\n";
    }
    return 0;
}