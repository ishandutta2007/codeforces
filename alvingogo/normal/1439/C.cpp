#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

struct ST{
    struct no{
        int sum,mn,tag;
    };
    vector<no> st;
    void init(int x){
        st.resize(4*x);
        build(0,0,x-1);
    }
    void build(int v,int L,int R){
        if(L==R){
            cin >> st[v].mn;
            st[v].sum=st[v].mn;
            st[v].tag=-1;
            return;
        }
        int m=(L+R)/2;
        build(2*v+1,L,m);
        build(2*v+2,m+1,R);
        pup(v);
        st[v].tag=0;
    }
    void upd(int v,int k,int sz){
        st[v].tag=k;
        st[v].mn=k;
        st[v].sum=k*sz;
    }
    void pudo(int v,int sz){
        if(st[v].tag==0){
            return;
        }
        upd(2*v+1,st[v].tag,(sz+1)/2);
        upd(2*v+2,st[v].tag,sz-(sz+1)/2);
        st[v].tag=0;
    }
    void pup(int v){
        st[v].sum=st[2*v+1].sum+st[2*v+2].sum;
        st[v].mn=min(st[2*v+1].mn,st[2*v+2].mn);
    }
    void update(int v,int L,int R,int l,int r,int k){
        if(l==L && r==R){
            upd(v,k,R-L+1);
            return;
        }
        pudo(v,R-L+1);
        int m=(L+R)/2;
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
    int q1(int v,int L,int R,int k){
        if(L==R){
            return st[v].mn<=k?L:-1;
        }
        int m=(L+R)/2;
        pudo(v,R-L+1);
        if(st[2*v+1].mn<=k){
            return q1(2*v+1,L,m,k);
        }
        else{
            return q1(2*v+2,m+1,R,k);
        }
    }
    pair<int,int> q2(int v,int L,int R,int l,int k){
        if(L==l){
            if(k>=st[v].sum){
                k-=st[v].sum;
                return {R-L+1,k};
            }
            else{
                if(L==R){
                    return {0,k};
                }
            }
        }
        pudo(v,R-L+1);
        int m=(L+R)/2;
        if(l>m){
            return q2(2*v+2,m+1,R,l,k);
        }
        else{
            auto y=q2(2*v+1,L,m,l,k);
            if(y.fs==m-l+1){
                auto z=q2(2*v+2,m+1,R,m+1,y.sc);
                return {y.fs+z.fs,z.sc};
            }
            else{
                return y;
            }
        }
    }
}st;
signed main(){
    AquA;
    int n,q;
    cin >> n >> q;
    st.init(n);
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t==1){
            int r,k;
            cin >> r >> k;
            r--;
            auto y=st.q1(0,0,n-1,k);
            if(y<=r && y>=0){
                st.update(0,0,n-1,y,r,k);
            }
        }
        else{
            int l,k;
            cin >> l >> k;
            l--;
            int ans=0;
            for(int j=0;j<35;j++){
                auto a=st.q1(0,0,n-1,k);
                if(a<0){
                    break;
                }
                if(max(a,l)>n-1){
                    break;
                }
                auto y=st.q2(0,0,n-1,max(a,l),k);
                k=y.sc;
                ans+=y.fs;
                l=max(l,a)+y.fs; 
            }
            cout << ans << "\n";
        }
    }
    return 0;
}