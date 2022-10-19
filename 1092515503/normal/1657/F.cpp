/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETEMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,fa[400100],dep[400100];
vector<int>v[400100],u[400100][26],w;
int tot[400100];
int dsu[800100];
int find(int x){return x==dsu[x]?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){x=find(x),y=find(y);if(x!=y)dsu[x]=y;}
char s[400100],r[400100],t[400100][2];
void dfs(int x){for(auto y:v[x])if(y!=fa[x])fa[y]=x,dep[y]=dep[x]+1,dfs(y);}
int LCA(int x,int y){
    if(dep[x]>dep[y])swap(x,y);
    while(dep[x]!=dep[y])y=fa[y];
    while(x!=y)x=fa[x],y=fa[y];
    return x;
}
vector<int>g[800100];
int col[800100];
void dye(int x){
    for(auto y:g[x]){
        if(col[y]==-1)col[y]=!col[x],dye(y);
        else if(col[y]==col[x]){puts("NO");exit(0);}
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
    dfs(1);
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%d%d",&x,&y);
        dsu[i]=i,dsu[i+m]=i+m;
        z=LCA(x,y);
        while(x!=z)w.push_back(x),x=fa[x];
        w.push_back(z),x=w.size();
        while(y!=z)w.push_back(y),y=fa[y];
        reverse(w.begin()+x,w.end());
 //       for(auto j:w)printf("%d ",j);puts("");
        scanf("%s",s);
        for(int j=0,k=(int)w.size()-1;j<(int)w.size();j++,k--)
            if(s[j]==s[k]){
                if(r[w[j]]&&r[w[j]]!=s[j]){puts("NO");return 0;}
                r[w[j]]=s[j];
            }else u[w[j]][s[j]-'a'].push_back(i),u[w[j]][s[k]-'a'].push_back(i+m),tot[w[j]]++;
        w.clear();
    }
    dsu[0]=0;
    for(int i=1;i<=n;i++)if(r[i]){
        if((int)u[i][r[i]-'a'].size()!=tot[i]){puts("NO");return 0;}
        for(auto x:u[i][r[i]-'a'])/*printf("%d ",x),*/merge(x,0);//puts("");
    }else{
        if(!tot[i])continue;
        int T=0;
        for(char j='a';j<='z';j++)if((int)u[i][j-'a'].size()==tot[i])t[i][T++]=j;
        if(!T){puts("NO");return 0;}
        if(T==1){r[i]=t[i][0];for(auto x:u[i][r[i]-'a'])/*printf("%d ",x),*/merge(x,0);/*puts("");*/continue;}
//        printf("%d:%c,%c\n",i,t[i][0],t[i][1]);
        for(auto x:u[i][t[i][0]-'a'])/*printf("%d ",x),*/merge(x,u[i][t[i][0]-'a'].back());//puts("");
        for(auto x:u[i][t[i][1]-'a'])/*printf("%d ",x),*/merge(x,u[i][t[i][1]-'a'].back());//puts("");
    }
    for(int i=1;i<=m;i++)if(find(i)==find(i+m)){puts("NO");return 0;}
    for(int i=1;i<=m;i++)g[find(i)].push_back(find(i+m)),g[find(i+m)].push_back(find(i));
    memset(col,-1,sizeof(col));
    for(int i=0;i<=(m<<1);i++)if(dsu[i]==i&&col[i]==-1)col[i]=0,dye(i);
    for(int i=1;i<=n;i++)if(tot[i]&&!r[i])r[i]=t[i][col[find(u[i][t[i][0]-'a'].back())]!=col[find(0)]];
    for(int i=1;i<=n;i++)if(!r[i])r[i]='a';
    puts("YES");
    printf("%s\n",r+1);
    return 0;
}