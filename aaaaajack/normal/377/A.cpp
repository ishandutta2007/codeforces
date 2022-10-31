#include<cstdio>
#include<queue>
#include<utility>
#include<queue>
#include<vector>
using namespace std;
char maze[510][510];
bool visit[510][510]={false};
int main(){
    int i,j,m,n,k;
    pair<int,int> start;
    vector<pair<int,int> > ans;
    scanf("%d%d%d",&m,&n,&k);
    for(i=0;i<m;i++){
        scanf("%s",maze[i]);
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(maze[i][j]=='.'){
                start=make_pair(i,j);
                visit[i][j]=true;
                i=m;
                j=n;
                }
        }
    }           
    queue<pair<int,int> > point;
    point.push(start);
    ans.push_back(start);
    while(!point.empty()){
        pair<int,int> temp=point.front();
        point.pop();
        int x=temp.first,y=temp.second;
        if(x>0&&!visit[x-1][y]&&maze[x-1][y]=='.'){
            visit[x-1][y]=true;
            point.push(make_pair(x-1,y));
            ans.push_back(make_pair(x-1,y));
        }
        if(y>0&&!visit[x][y-1]&&maze[x][y-1]=='.'){
            visit[x][y-1]=true;
            point.push(make_pair(x,y-1));
            ans.push_back(make_pair(x,y-1));
        }
        if(x<m-1&&!visit[x+1][y]&&maze[x+1][y]=='.'){
            visit[x+1][y]=true;
            point.push(make_pair(x+1,y));
            ans.push_back(make_pair(x+1,y));
        }
        if(y<n-1&&!visit[x][y+1]&&maze[x][y+1]=='.'){
            visit[x][y+1]=true;
            point.push(make_pair(x,y+1));
            ans.push_back(make_pair(x,y+1));
        }
    }
    for(i=ans.size()-1;i>=ans.size()-k;i--){
        maze[ans[i].first][ans[i].second]='X';
    }
    for(i=0;i<m;i++){
        puts(maze[i]);
    }
    return 0;
}