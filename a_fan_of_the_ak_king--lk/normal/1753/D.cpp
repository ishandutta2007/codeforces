#include<bits/stdc++.h>
using namespace std;
const int N=2000005,M=998244353;
int k,head[N],Next[N*2],adj[N*2],leng[N*2],vis[N],n;
long long d[N];
struct str{
    long long d;
    int x;
};
bool operator <(str a,str b)
{
    return a.d>b.d;
}
priority_queue<str> q;
void Push(int u,int v,int w)
{
    // cout<<u<<' '<<v<<' '<<w<<endl;
    Next[++k]=head[u];
    head[u]=k;
    adj[k]=v;
    leng[k]=w;
}
void Dij(int S)
{
    int i,j;
    for(i=0;i<=n;++i)
    {
        d[i]=1000000000000000000ll;
        vis[i]=0;
    }
    d[S]=0;
    q.push((str){0,S});
    while(!q.empty())
    {
        str x=q.top();
        q.pop();
        if(vis[x.x])
            continue;
        vis[x.x]=1;
        for(j=head[x.x];j;j=Next[j])
            if(d[adj[j]]>d[x.x]+leng[j])
            {
                d[adj[j]]=d[x.x]+leng[j];
                q.push((str){d[adj[j]],adj[j]});
            }
    }
}
int h,w,A,B;
char c[N];
string p[N];
int id(int x,int y){
    return (x-1)*w+y+1;
}
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void Mg(int d,int x,int y){
    for(int i=0;i<4;++i)
        if(i!=d&&dx[i]+x>=1&&dx[i]+x<=h&&dy[i]+y>=0&&dy[i]+y<w){
            int uu=id(x+dx[i],y+dy[i]),vv=id(x+dx[d],y+dy[d]);
            if(p[x+dx[i]][y+dy[i]]=='#')
                continue;
            if(x+y&1)
                swap(uu,vv);
            Push(uu,vv,(abs(dx[i])==abs(dx[d])?A:B));
        }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d %d",&h,&w);
    n=h*w+1;
    scanf("%d %d",&A,&B);
    swap(A,B);
    for(int i=1;i<=h;++i){
        scanf("%s",c);
        for(int j=0;j<w;++j)
            p[i]+=c[j];
    }
    for(int i=1;i<=h;++i)
        for(int j=0;j<w;++j){
            if(p[i][j]=='L')
                Mg(2,i,j);
            if(p[i][j]=='R')
                Mg(3,i,j);
            if(p[i][j]=='U')
                Mg(0,i,j);
            if(p[i][j]=='D')
                Mg(1,i,j);
                if(i+j&1){
                    if(p[i][j]=='.')
                        Push(0,id(i,j),0);
                    for(int u=0;u<4;++u){
                        int x=dx[u]+i;
                        int y=dy[u]+j;
                        if(x>=1&&x<=h&&y>=0&&y<w&&p[x][y]!='#')
                            Push(id(i,j),id(x,y),0);
                    }
                }
                if((i+j&1^1)&&p[i][j]=='.')
                    Push(id(i,j),h*w+1,0);
        }
    Dij(0);
    if(d[h*w+1]>=1000000000000000000ll)
        puts("-1");
    else
        cout<<d[h*w+1];
}