#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

vector<int> dfn,low,cc,vis,lp,sum;
stack<int> s;
int cnt=0,tt=0;
vector<vector<pair<int,int> > > e;
void dfs(int r){
    cnt++;
    dfn[r]=low[r]=cnt;
    s.push(r);
    for(auto h:e[r]){
        if(cc[h.fs]==0){
            if(dfn[h.fs]){
                low[r]=min(low[r],dfn[h.fs]);
            }
            else{
                dfs(h.fs);
                low[r]=min(low[r],low[h.fs]);
            }
        }
    }
    if(dfn[r]==low[r]){
        tt++;
        while(s.size() && s.top()!=r){
            cc[s.top()]=tt;
            s.pop();
        }
        cc[r]=tt;
        s.pop();
    }
}
void dfs2(int r){
    vis[r]=1;
    for(auto h:e[r]){
        if(cc[h.fs]==cc[r]){
            if(!vis[h.fs]){
                sum[h.fs]=h.sc+sum[r];
                dfs2(h.fs);
            }
            else{
                int z=abs(sum[r]+h.sc-sum[h.fs]);
                if(z){
                    lp[cc[r]]=__gcd(lp[cc[r]],z);
                }                   
            }
        }
    }
}
signed main(){
    AquA;
    int n;
    cin >> n;
    dfn.resize(n);
    low.resize(n);
    cc.resize(n);
    e.resize(n);
    vis.resize(n);
    sum.resize(n);
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        e[a].push_back({b,c});
    }
    for(int i=0;i<n;i++){
        if(!dfn[i]){
            dfs(i);
        }
    }
    lp.resize(tt+1);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            assert(lp[cc[i]]==0);
            dfs2(i);
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a,s,t;
        cin >> a >> s >> t;
        a--;
        if(s==0){
            cout << "YES\n";
            continue;
        }
        if(lp[cc[a]]!=0 && s%(__gcd(lp[cc[a]],t))==0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}