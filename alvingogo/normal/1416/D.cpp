#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct ST{
    vector<pair<int,int> > st;
    void init(int x){
        st.resize(4*x);
    }
    void update(int v,int L,int R,int p,pair<int,int> k){
        if(L==R){
            st[v]=k;
            return;
        }
        int m=(L+R)/2;
        if(p<=m){
            update(2*v+1,L,m,p,k);
        }
        else{
            update(2*v+2,m+1,R,p,k);
        }
        st[v]=max(st[2*v+1],st[2*v+2]);
    }
    pair<int,int> query(int v,int L,int R,int l,int r){
        if(l==L && r==R){
            return st[v];
        }
        int m=(L+R)/2;
        if(r<=m){
            return query(2*v+1,L,m,l,r);
        }
        else if(l>m){
            return query(2*v+2,m+1,R,l,r);
        }
        else{
            return max(query(2*v+1,L,m,l,m),query(2*v+2,m+1,R,m+1,r));
        }
    }
}st;
struct TREE{
    struct no{
        vector<int> ch;
        int in=-1,out=-1;
    };
    int cnt=-1,n;
    vector<no> v;
    void init(int x){
        n=x;
        v.resize(n);
        n/=2;
    }
    void edge(int x,int y){
        v[x].ch.push_back(y);
        v[y].ch.push_back(x);
    }
    void dfs(int r,int f,vector<int>& val){
        v[r].in=cnt+1;
        for(auto h:v[r].ch){
            if(h!=f){
                dfs(h,r,val);
            }
        }
        v[r].out=cnt;
        if(v[r].in>v[r].out){
            cnt++;
            v[r].out++;
            st.update(0,0,n-1,cnt,{val[r],cnt});
        }
    }
}tr;
struct DSU{
    vector<int> bo;
    int cnt=0;
    void init(int x){
        bo.resize(x);
        cnt=x/2;
        iota(bo.begin(),bo.end(),0);
    }
    int find(int x){
        return x==bo[x]?x:bo[x]=find(bo[x]);
    }
    void merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return;
        }
        int z=cnt;
        cnt++;
        bo[x]=bo[y]=z;
        tr.edge(z,x);
        tr.edge(z,y);
    }
}dsu;
int main(){
    AquA;
    int n,m,q;
    cin >> n >> m >> q;
    dsu.init(2*n);
    tr.init(2*n);
    st.init(n);
    vector<int> val(n);
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    vector<pair<int,int> > e(m);
    vector<int> a(m,-1);
    for(int i=0;i<m;i++){
        cin >> e[i].fs >> e[i].sc;
        e[i].fs--;
        e[i].sc--;
    }
    vector<pair<int,int> > vq(q);
    vector<int> z(q,-1);
    for(int i=0;i<q;i++){
        cin >> vq[i].fs >> vq[i].sc;
        vq[i].sc--;
        if(vq[i].fs==2){
            a[vq[i].sc]=i;
        }
    }
    for(int i=0;i<m;i++){
        if(a[i]==-1){
            dsu.merge(e[i].fs,e[i].sc);
        }
    }
    for(int i=q-1;i>=0;i--){
        if(vq[i].fs==1){
            z[i]=dsu.find(vq[i].sc);
        }
        else{
            dsu.merge(e[vq[i].sc].fs,e[vq[i].sc].sc);
        }
    }
    for(int i=0;i<dsu.cnt;i++){
        if(dsu.bo[i]==i){
            tr.dfs(i,i,val);
        }
    }
    for(int i=0;i<q;i++){
        if(vq[i].fs==1){
            auto h=st.query(0,0,n-1,tr.v[z[i]].in,tr.v[z[i]].out);
            cout << h.fs << "\n";
            st.update(0,0,n-1,h.sc,{0,h.sc});
        }
    }
    return 0;
}