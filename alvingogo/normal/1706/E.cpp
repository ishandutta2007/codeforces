#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

vector<int> ans;
struct DSU{
    vector<int> bo,ss;
    vector<vector<int> > ch;
    void init(int x){
        bo.resize(x);
        ss.resize(x,1);
        iota(bo.begin(),bo.end(),0);
        ch.resize(x);
        for(int i=0;i<x;i++){
            ch[i].push_back(i);
        }
    }
    int find(int x){
        return bo[x]==x?x:bo[x]=find(bo[x]);
    }
    void merge(int x,int y,int t){
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
        for(auto h:ch[y]){
            if(h>0 && find(h)==find(h-1)){
                ans[h-1]=min(ans[h-1],t);
            }
            if(h+1<bo.size() && find(h)==find(h+1)){
                ans[h]=min(ans[h],t);
            }
            ch[x].push_back(h);
        }
    }
};
struct SZT{
    vector<int> v[19];
    void build(int n){
        for(int i=0;i<19;i++){
            v[i].resize(n);
        }
        for(int i=0;i<n;i++){
            v[0][i]=ans[i];
        }
        for(int i=1;i<19;i++){
            for(int j=0;j<n;j++){
                if(j+(1<<i)<=n){
                    v[i][j]=max(v[i-1][j],v[i-1][j+(1<<(i-1))]);
                }
            }
        }
    }
    int query(int l,int r){
        if(l>r){
            return 0;
        }
        int a=__lg(r-l+1);
        return max(v[a][l],v[a][r-(1<<a)+1]);
    }
};
int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n,m,q;
        cin >> n >> m >> q;
        DSU dsu;
        dsu.init(n);
        ans.clear();
        ans.resize(n-1,1e9);
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            dsu.merge(a,b,i+1);
        }
        SZT st;
        st.build(n-1);
        for(int i=0;i<q;i++){
            int l,r;
            cin >> l >> r;
            l--;
            r--;
            cout << st.query(l,r-1) << " ";
        }
        cout << '\n';
    }
    return 0;
}