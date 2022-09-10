#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> V[2505];

string s[55];

bool ko=false;

bool visited[2505];

int parent[2505];

void dfs(int u){
     visited[u]=true;
     int x=V[u].size();
     for(int i=0;i<x;++i)
             if(!visited[V[u][i]]){
                            parent[V[u][i]]=u;
                            dfs(V[u][i]);
             }
             else{
                  if(V[u][i]!=parent[u]){
                                         ko=true;
                                         break;
                  }
             }
}

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;++i){
            char t[55];
            scanf("%s", t);
            s[i]=t;
    }
    for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                    if(i>0&&s[i-1][j]==s[i][j])
                                               V[m*i+j].push_back(m*i+j-m);
                    if(j>0&&s[i][j-1]==s[i][j])
                                               V[m*i+j].push_back(m*i+j-1);
                    if(i<(n-1)&&s[i+1][j]==s[i][j])
                                               V[m*i+j].push_back(m*i+j+m);
                    if(j<(m-1)&&s[i][j+1]==s[i][j])
                                               V[m*i+j].push_back(m*i+j+1);
            }
    }
    for(int i=0;i<n*m;++i){
            if(!visited[i])
                           dfs(i);
            if(ko)
                  break;
    }
    if(ko)
          puts("Yes");
    else
        puts("No");
    return 0;
}