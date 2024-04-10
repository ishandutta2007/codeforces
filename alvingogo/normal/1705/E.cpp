#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct ST{
    struct no{
        int mn,mx,my,tag,mz;
        no(){
            tag=0;
            mn=0;
            mx=-1;
            mz=1e7;
            my=1e7;
        }
    };
    vector<no> st;
    void init(int x){
        st.resize(4*x);
        build(0,0,x-1);
    }
    void build(int v,int L,int R){
        if(L==R){
            st[v].mz=L;
            return;
        }
        int m=(L+R)/2;
        build(2*v+1,L,m);
        build(2*v+2,m+1,R);
        pup(v);
    }
    void upd(int v,int k,int L,int R){
        st[v].tag+=k;
        st[v].mn+=k;
        if(st[v].mn){
            st[v].mz=1e7;
            st[v].mx=R;
            st[v].my=L;
        }
        else{
            st[v].mz=L;
            st[v].mx=-1;
            st[v].my=1e7;
        }
    }
    void pudo(int v,int L,int R){
        if(st[v].tag==0){
            return;
        }
        int m=(L+R)/2;
        upd(2*v+1,st[v].tag,L,m);
        upd(2*v+2,st[v].tag,m+1,R);
        st[v].tag=0;
    }
    void pup(int v){
        st[v].mn=min(st[2*v+1].mn,st[2*v+2].mn);
        st[v].mx=max(st[2*v+1].mx,st[2*v+2].mx);
        st[v].mz=min(st[2*v+1].mz,st[2*v+2].mz);
        st[v].my=min(st[2*v+1].my,st[2*v+2].my);
    }
    void update(int v,int L,int R,int l,int r,int k){
        if(L==l && r==R){
            upd(v,k,L,R);
            return;
        }
        int m=(L+R)/2;
        pudo(v,L,R);
        if(r<=m){
            update(2*v+1,L,m,l,r,k);
        }
        else if(l>m){
            update(2*v+2,m+1,R,l,r,k);
        }
        else{
            update(2*v+1,L,m,l,m,k);
            update(2*v+2,m+1,R,m+1,r,k);
        }
        pup(v);
    }
    int query(int v,int L,int R,int l,int r){
        if(l==L && r==R){
            return st[v].mz;
        }
        int m=(L+R)/2;
        pudo(v,L,R);
        if(r<=m){
            return query(2*v+1,L,m,l,r);
        }
        else if(l>m){
            return query(2*v+2,m+1,R,l,r);
        }
        else{
            auto h=query(2*v+1,L,m,l,m);
            if(h>m){
                return query(2*v+2,m+1,R,m+1,r);
            }
            else{
                return h;
            }
        }
    }
    int query2(){
        return st[0].mx;
    }
    int query3(int v,int L,int R,int l,int r){
        if(l==L && r==R){
            return st[v].my;
        }
        int m=(L+R)/2;
        pudo(v,L,R);
        if(r<=m){
            return query3(2*v+1,L,m,l,r);
        }
        else if(l>m){
            return query3(2*v+2,m+1,R,l,r);
        }
        else{
            auto h=query3(2*v+1,L,m,l,m);
            if(h>m){
                return query3(2*v+2,m+1,R,m+1,r);
            }
            else{
                return h;
            }
        }
    }
};
int main(){
    AquA;
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    p_q<int,vector<int>,greater<int> > pq;
    for(int i=0;i<n;i++){
        cin >> v[i];
        pq.push(v[i]);
    }
    ST st;
    const int m=2e5+100;
    st.init(m);
    while(pq.size()){
        auto h=pq.top();
        pq.pop();
        if(pq.empty()){
            st.update(0,0,m-1,h,h,1);
            break;
        }
        if(h==pq.top()){
            pq.pop();
            pq.push(h+1);
        }
        else{
            st.update(0,0,m-1,h,h,1);
        }
    }
    for(int i=0;i<q;i++){
        int a,p;
        cin >> a >> p;
        a--;
        auto y=st.query3(0,0,m-1,v[a],m-1);
        if(y==v[a]){
            st.update(0,0,m-1,v[a],v[a],-1);
        }
        else{
            st.update(0,0,m-1,v[a],y-1,1);
            st.update(0,0,m-1,y,y,-1);
        }
        v[a]=p;
        auto x=st.query(0,0,m-1,v[a],m-1);
        if(x==v[a]){
            st.update(0,0,m-1,v[a],v[a],1);
        }
        else{
            st.update(0,0,m-1,v[a],x-1,-1);
            st.update(0,0,m-1,x,x,1);
        }
        cout << st.query2() << "\n";
    }
    return 0;
}