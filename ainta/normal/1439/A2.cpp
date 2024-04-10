#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
char p[110][110];
struct point{
    int x, y;
};
void Solve(){
    int i, j, k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]+1);
    }
    vector<vector<point>>Res;
    for(i=1;i<n-1;i++){
        for(j=1;j<m;j++){
            if(p[i][j]=='0' && p[i][j+1]=='0')continue;
            vector<point>V;
            if(p[i][j]=='1'){
                V.push_back({i,j});
            }
            if(p[i][j+1]=='1')V.push_back({i,j+1});
            for(k=j;k<=j+1;k++){
                if(V.size()<3)V.push_back({i+1,k});
            }
            Res.push_back(V);
            for(auto &t : V){
                p[t.x][t.y]='1'-p[t.x][t.y]+'0';
            }
        }
    }
    for(j=1;j<m;j++){
        if(p[n][j]=='0' && p[n-1][j]=='0')continue;
        vector<point>V;
        if(p[n][j]=='1'){
            V.push_back({n,j});
        }
        if(p[n-1][j]=='1'){
            V.push_back({n-1,j});
        }
        for(k=n-1;k<=n;k++){
            if(V.size()<3)V.push_back({k,j+1});
        }
        Res.push_back(V);
        for(auto &t : V){
            p[t.x][t.y]='1'-p[t.x][t.y]+'0';
        }
    }
    if(p[n-1][m]=='1' && p[n][m]=='0'){
        vector<point>V;
        V.push_back({n-1,m});
        V.push_back({n,m});
        V.push_back({n-1,m-1});
        Res.push_back(V);
        V.clear();
        V.push_back({n-1,m-1});
        V.push_back({n-1,m});
        V.push_back({n,m-1});
        Res.push_back(V);
        V.clear();
        V.push_back({n-1,m});
        V.push_back({n,m-1});
        V.push_back({n,m});
        Res.push_back(V);
    }
    else if(p[n-1][m]=='0' && p[n][m]=='1'){
        vector<point>V;
        V.push_back({n-1,m});
        V.push_back({n,m});
        V.push_back({n-1,m-1});
        Res.push_back(V);
        V.clear();
        V.push_back({n-1,m-1});
        V.push_back({n,m});
        V.push_back({n,m-1});
        Res.push_back(V);
        V.clear();
        V.push_back({n,m});
        V.push_back({n,m-1});
        V.push_back({n-1,m});
        Res.push_back(V);

    }
    else if(p[n-1][m]=='1' && p[n][m]=='1'){
        vector<point>V;
        V.push_back({n-1,m-1});
        V.push_back({n-1,m});
        V.push_back({n,m-1});
        Res.push_back(V);
        V.clear();
        V.push_back({n-1,m-1});
        V.push_back({n,m-1});
        V.push_back({n,m});
        Res.push_back(V);
    }
    printf("%d\n",Res.size());
    for(auto &t : Res){
        for(auto &x : t){
            printf("%d %d ",x.x,x.y);
        }
        puts("");
    }
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}