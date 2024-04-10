#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct no{
    vector<int> ch;
    int a;
    int in=0,out=0;
    int tmp=-1;
};
vector<no> v;
vector<vector<int> > p;
vector<int> vis,cnt,st,ck,chg;
int zz=1,ans=0;
int cz=0;
int y=0;
void dfs(int r,int f){
    cz++;
    v[r].in=cz;
    p[v[r].a].push_back(r);
    int u=0;
    if(!vis[v[r].a]){
        vis[v[r].a]=1;
        u=1;
    }
    else{
        cnt[v[r].a]++;
        chg[v[r].a]++;
        if(cnt[v[r].a]>=2){
            zz=0;
        }
    }
    int dr=0;
    for(auto h:v[r].ch){
        if(h!=f){
            dfs(h,r);
        }
        if(u && chg[v[r].a]){
            dr++;
            chg[v[r].a]=0;
        }
    }
    if(u && dr>=2){
        zz=0;
    }
    cz++;
    v[r].out=cz;
    if(!u){
        cnt[v[r].a]--;
    }
}
bool as(int a,int b){
    return v[a].in<v[b].in && v[a].out>v[b].out;
}
void dfs2(int r,int f,int e){
    if(st[v[r].a]==-1){
        return;
    }
    if(st[v[r].a]==1){
        if(ck[v[r].a]==1){
            return;
        }
    }
    if(v[r].tmp!=-1){
        ck[v[r].tmp]++;
        e++;
    }
    if(e==y && st[v[r].a]==0){
        ans++;
    }
    for(auto h:v[r].ch){
        if(h!=f){
            dfs2(h,r,e);
        }
    }
    if(st[v[r].a]==1){
        ck[v[r].a]--;
    }
}
int main(){
    AquA;
    int n;
    cin >> n;
    vis.resize(n);
    cnt.resize(n);
    v.resize(n);
    p.resize(n);
    st.resize(n);
    ck.resize(n);
    chg.resize(n);
    vector<int> gg;
    for(int i=0;i<n;i++){
        cin >> v[i].a;
        gg.push_back(v[i].a);
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v[a].ch.push_back(b);
        v[b].ch.push_back(a);
    }
    sort(gg.begin(),gg.end());
    gg.erase(unique(gg.begin(),gg.end()),gg.end());
    for(int i=0;i<n;i++){
        v[i].a=lower_bound(gg.begin(),gg.end(),v[i].a)-gg.begin();
    }
    dfs(0,0);
    if(zz==0){
        cout << 0 << "\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        int nw=0;
        for(int j=1;j<(int)p[i].size();j++){
            if(as(p[i][0],p[i][j])){
                if(nw==-1){
                    cout << 0 << "\n";
                    return 0;
                }
                nw=1;
            }
            else{
                if(nw==1){
                    cout << 0 << "\n";
                    return 0;
                }
                nw=-1;
            }
        }
        st[i]=nw;
        if(nw==1){
            for(auto h:v[p[i][0]].ch){
                if(!as(h,p[i][0]) && as(h,p[i][1])){
                    v[h].tmp=i;
                }
            }
            y++;
        }
    }
    dfs2(0,0,0);
    cout << ans << "\n";
    return 0;
}