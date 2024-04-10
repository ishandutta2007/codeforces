#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

vector<int> adj[100001];
vector<pair<int,int> > sna;
int area[100001], idx=1;
int cnt1[100001], cnt2[100001];

void dfs(int x){
    area[x]=idx;
    cnt1[idx]++;
    for(int i=0;i<adj[x].size();i++){
        if(area[adj[x][i]]==0){
            dfs(adj[x][i]);
        }
    }
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        sna.emplace_back(a,b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(area[i]==0){
            dfs(i);
            idx++;
        }
    }
    for(int i=0;i<k;i++){
        cnt2[area[sna[i].first]]++;
    }
    int ans = 0;
    for(int i=1;i<idx;i++){
        if(cnt1[i]<=cnt2[i]) ans += cnt2[i]-cnt1[i]+1;
    }
    printf("%d\n",ans);
}