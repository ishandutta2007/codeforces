#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct Dinic{
    struct edge{
        int to,cap,rev;
        edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
    };

    const int INF=1001001001;
    vector<vector<edge>>G;
    vector<int>level,iter;
    Dinic(int v):G(v),level(v),iter(v){}

    void addEdge(int from,int to,int cap){
        G[from].push_back(edge(to,cap,G[to].size()));
        G[to].push_back(edge(from,0,G[from].size()-1));
    }

    void bfs(int s){
        fill(level.begin(),level.end(),-1);
        queue<int>que;
        level[s]=0;
        que.push(s);
        while(que.size()){
            int v=que.front();
            que.pop();
            for(auto &e:G[v]){
                if(e.cap&&level[e.to]==-1){
                    level[e.to]=level[v]+1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v,int t,int f){
        if(v==t)return f;
        for(int &i=iter[v];i<G[v].size();i++){
            edge &e=G[v][i];
            if(e.cap>0&&level[v]<level[e.to]){
                int d=dfs(e.to,t,min(f,e.cap));
                if(d>0){
                    e.cap-=d;
                    G[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s,int t){
        int flow=0;
        while(true){
            bfs(s);
            if(level[t]<0)return flow;
            fill(iter.begin(),iter.end(),0);
            int f;
            while((f=dfs(s,t,INF))>0)flow+=f;
        }
    }
};

int N,M;
int A[5555],B[5555];

bool check(int x){
    Dinic d(N+2);
    int src=N;
    int snk=N+1;

    vint cnt(N);
    rep(i,M){
        cnt[A[i]]++;
        d.addEdge(A[i],B[i],1);
    }

    int f=0;

    rep(i,N){
        if(cnt[i]>x){
            d.addEdge(src,i,cnt[i]-x);
            f+=cnt[i]-x;
        }
        else if(cnt[i]<x){
            d.addEdge(i,snk,x-cnt[i]);
        }
    }
    if(d.maxFlow(src,snk)!=f)return false;

    set<pint>es;
    rep(i,N)for(auto &e:d.G[i])if(e.cap)es.insert({i,e.to});
    rep(i,M){
        if(es.find({A[i],B[i]})==es.end())swap(A[i],B[i]);
    }
    return true;
}

signed main(){
    cin>>N>>M;
    rep(i,M)cin>>A[i]>>B[i],A[i]--,B[i]--;

    int lb=0,ub=M;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(check(mid))ub=mid;
        else lb=mid;
    }


    check(ub);
    cout<<ub<<endl;
    rep(i,M)cout<<A[i]+1<<" "<<B[i]+1<<endl;
    return 0;
}