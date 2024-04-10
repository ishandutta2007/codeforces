#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;
 
struct no{
    vector<pair<int,int> > ch;
    pair<int,int> fa;
    int dep=-1;
};
vector<no> v;
void dfs(int r,pair<int,int> f){
    v[r].fa=f;
    v[r].dep=v[f.fs].dep+1;
    for(auto h:v[r].ch){
        if(h.fs!=f.fs){
            dfs(h.fs,{r,h.sc});
        }
    }
}
struct DSU{
    vector<int> bo,ss,bon;
    void init(int n){
        bo.resize(n);
        bon.resize(n,-1);
        iota(bo.begin(),bo.end(),0);
        ss.resize(n,1);
    }
    int find(int x){
        return bo[x]==x?x:find(bo[x]);
    }
    int merge(int x,int y,int z){
        int a=x,b=y;
        x=find(x);
        y=find(y);
        if(x==y){
            return 0;
        }
        v[a].ch.push_back({b,z});
        v[b].ch.push_back({a,z});
        if(ss[x]>ss[y]){
            swap(x,y);
        }
        bo[x]=y;
        bon[x]=z;
        ss[y]+=ss[x];
        return 1;
    }
    int as(int x,int y){
        while(x!=y && bo[x]!=x){
            x=bo[x];
            if(x==y){
                return 1;
            }
        }
        return 0;
    }
};
int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        DSU dsu;
        dsu.init(n);
        v.clear();
        v.resize(n);
        vector<pair<pair<int,int>,int> > e;
        string s;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            if(!dsu.merge(a,b,i)){
                e.push_back({{min(a,b),max(a,b)},i});
                s+='1';
            }
            else{
                s+='0';
            }
        }
        if(e.size()==3){
            set<int> sa;
            for(auto h:e){
                sa.insert(h.fs.fs);
                sa.insert(h.fs.sc);
            }
            if(sa.size()==3){
                dfs(0,{0,-1});
                vector<int> c;
                for(auto h:sa){
                    c.push_back(h);
                }
                int minx=c[0];
                if(v[c[1]].dep>v[minx].dep){
                    minx=c[1];
                }
                if(v[c[2]].dep>v[minx].dep){
                    minx=c[2];
                }
                s[v[minx].fa.sc]='1';
                for(auto h:e){
                    if(h.fs.fs==minx || h.fs.sc==minx){
                        s[h.sc]='0';
                        break;
                    }
                }
            }
        }
        cout << s << '\n';
    }
    return 0;
}