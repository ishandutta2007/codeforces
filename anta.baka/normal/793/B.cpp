#include <bits/stdc++.h>

using namespace std;

const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
struct cell{
    int i,j,dir;
};
int n,m,X,Y,f[1000][1000][4];
char a[1000][1000];
queue<cell> q;

int main(){
    cin>>n>>m;
    memset(f,3,sizeof f);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='S')q.push({i,j,0}),q.push({i,j,1}),q.push({i,j,2}),q.push({i,j,3}),f[i][j][0]=0,f[i][j][1]=0,f[i][j][2]=0,f[i][j][3]=0;
            if(a[i][j]=='T')X=i,Y=j;
        }
    while(!q.empty()){
        cell me=q.front();
        q.pop();
        if(me.i==X&&me.j==Y)return cout<<"YES",0;
        for(int w=0;w<4;w++){
            int i=me.i+dx[w],j=me.j+dy[w];
            if(i<0||j<0||i>=n||j>=m||a[i][j]=='*')continue;
            if(f[i][j][w]<=f[me.i][me.j][me.dir]+(w!=me.dir))continue;
            if(f[me.i][me.j][me.dir]==2&&w!=me.dir)continue;
            f[i][j][w]=f[me.i][me.j][me.dir]+(w!=me.dir);
            q.push({i,j,w});
        }
    }
    cout<<"NO";
}