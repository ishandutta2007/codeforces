#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

vector<vector<int> > sa,df;
vector<int> cr;
vector<int> c;
int dfs(int x,int t){
    cr[x]=t;
    for(auto h:sa[x]){
        if(!cr[h]){
            if(dfs(h,-t)){
                return 1;
            }
        }
        else{
            if(cr[h]+cr[x]!=0){
                return 1;
            }
        }
    }
    return 0;
}
struct DSU{
    vector<int> bo,ss,zk;
    void init(int x){
        bo.resize(x);
        ss.resize(x,1);
        iota(bo.begin(),bo.end(),0);
        zk.resize(x,1);
    }
    int find(int x){
        return bo[x]==x?x:find(bo[x]);
    }
    int finda(int x){
        return bo[x]==x?1:finda(bo[x])*zk[x];
    }
    int lca(int x,int y){
        return finda(x)*finda(y);
    }
    void merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return;
        }
        if(ss[x]<ss[y]){
            swap(x,y);
        }
        bo[y]=x;
        ss[x]+=ss[y];
    }
    vector<pair<pair<int,int>,int> > mk;
    void merge2(int x,int y,int a){
        int b=finda(x),c=finda(y);
        x=find(x);
        y=find(y);
        if(x==y){
            return;
        }
        if(ss[x]<ss[y]){
            swap(x,y);
            swap(b,c);
        }
        mk.push_back({{x,y},zk[y]});
        a*=b;
        a*=c;
        zk[y]*=a;
        bo[y]=x;
        ss[x]+=ss[y];
    }
    void undo(){    
        while(mk.size()){
            auto h=mk.back();
            mk.pop_back();
            bo[h.fs.sc]=h.fs.sc;
            ss[h.fs.fs]-=ss[h.fs.sc];
            zk[h.fs.sc]=h.sc;
        }
    }
};
int main(){
    AquA;
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int> > z(k);
    sa.resize(n);
    c.resize(n);
    df.resize(n);
    cr.resize(n);
    for(int i=0;i<n;i++){
        cin >> c[i];
        c[i]--;
        z[c[i]].push_back(i);
    }
    for(int j=0;j<m;j++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if(c[a]==c[b]){
            sa[a].push_back(b);
            sa[b].push_back(a);
            continue;
        }
        if(c[a]<c[b]){
            swap(a,b);
        }
        df[a].push_back(b);
    }
    DSU dsu;
    dsu.init(n);
    vector<int> ab(k,1);
    for(int i=0;i<k;i++){
        for(auto h:z[i]){
            if(!cr[h]){
                if(dfs(h,1)){
                    ab[i]=0;
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<k;i++){
        if(ab[i]){
            ans++;
        }
        for(auto h:z[i]){
            for(auto y:sa[h]){
                dsu.merge(h,y);
            }
        }
    }
    ans=ans*(ans-1)/2;
    map<int,vector<pair<int,int> > > gg;
    auto get=[&](int pd){
        for(auto mp:gg[pd]){
            auto h=mp.fs;
            auto y=mp.sc;
            auto b=dsu.find(h);
            auto d=dsu.find(y);
            if(b==d){
                if(dsu.lca(h,y)!=cr[h]*cr[y]){
                    return 1;
                }
            }
            else{
                dsu.merge2(h,y,cr[h]*cr[y]);
            }
        }
        return 0;
    };
    for(int i=0;i<k;i++){
        if(ab[i]){
            set<int> sn;
            for(auto h:z[i]){
                for(auto y:df[h]){
                    if(ab[c[y]]){
                        gg[c[y]].push_back({h,y});
                        sn.insert(c[y]);
                    }
                }
            }
            for(auto j:sn){
                ans-=get(j);
                dsu.undo();
            }
            gg.clear();
        }
    }
    cout << ans << "\n";
    return 0;
}