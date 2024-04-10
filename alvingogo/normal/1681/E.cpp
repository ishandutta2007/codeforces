#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

vector<array<pair<int,int>,2> > a;
int c[2]={0};
int dis(pair<int,int> x,pair<int,int> y){
    int n=max(x.fs,x.sc);
    assert(n==max(y.fs,y.sc));
    return abs(x.fs-y.fs)+abs(x.sc-y.sc);
}
struct ST{
    vector<array<array<int,2>,2> > st;
    void init(int x){
        st.resize(4*x);
    }
    void build(int v,int L,int R){
        if(R<L){
            return;
        }
        if(L==R){
            st[v][0][0]=dis({a[L][0].fs+1,a[L][0].sc},a[L+1][0])+1;
            st[v][0][1]=dis({a[L][0].fs+1,a[L][0].sc},a[L+1][1])+1;
            //st[v][0][0]=min(dis(a[L][0],a[L][1])+st[v][1][0]+1,st[v][0][0]);
            //st[v][0][1]=min(dis(a[L][0],a[L][1])+st[v][1][1]+1,st[v][0][1]);
            st[v][1][0]=dis({a[L][1].fs,a[L][1].sc+1},a[L+1][0])+1;
            st[v][1][1]=dis({a[L][1].fs,a[L][1].sc+1},a[L+1][1])+1;
            //st[v][1][0]=min(dis(a[L][0],a[L][1])+st[v][0][0]+1,st[v][1][0]);
            //st[v][1][1]=min(dis(a[L][0],a[L][1])+st[v][0][1]+1,st[v][1][1]);
            return;
        }
        int m=(L+R)/2;
        build(2*v+1,L,m);
        build(2*v+2,m+1,R);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                st[v][i][j]=min(st[2*v+1][i][0]+st[2*v+2][0][j],st[2*v+1][i][1]+st[2*v+2][1][j]);
            }
        }
    }
    void query(int v,int L,int R,int l,int r){
        if(R<L){
            return;
        }
        if(L==l && r==R){
            int g=c[0],h=c[1];
            for(int i=0;i<2;i++){
                c[i]=min(g+st[v][0][i],h+st[v][1][i]);
            }
            return;
        }  
        int m=(L+R)/2;
        if(r<=m){
            query(2*v+1,L,m,l,r);
        }
        else if(l>m){
            query(2*v+2,m+1,R,l,r);
        }
        else{
            query(2*v+1,L,m,l,m);
            query(2*v+2,m+1,R,m+1,r);
        }
    }
};
int get(pair<int,int> d,pair<int,int> e){
    int ld=max(d.fs,d.sc);
    int le=max(e.fs,e.sc);
    assert(le==ld+1);
    return min(dis(d,a[ld][0])+dis(e,{a[ld][0].fs+1,a[ld][0].sc}),dis(d,a[ld][1])+dis(e,{a[ld][1].fs,a[ld][1].sc+1}))+1;
}
signed main(){
    AquA;
    int n;
    cin >> n;
    ST st;
    st.init(n);
    a.resize(n+1);
    for(int i=1;i<n;i++){
        cin >> a[i][0].fs >> a[i][0].sc >> a[i][1].fs >> a[i][1].sc;
    }
    st.build(0,1,n-2);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        pair<int,int> d,e;
        cin >> d.fs >> d.sc >> e.fs >> e.sc;
        int ld=max(d.fs,d.sc);
        int le=max(e.fs,e.sc);
        if(ld==le){
            cout << dis(d,e) << "\n";
            continue;
        }
        if(ld>le){
            swap(d,e);
            swap(ld,le);
        }
        if(le-ld==1){
            cout << get(d,e) << "\n";
        }
        else{
            c[0]=dis(d,a[ld][0]);
            c[1]=dis(d,a[ld][1]);
            st.query(0,1,n-2,ld,le-2);
            cout << min(c[0]+get(a[le-1][0],e),c[1]+get(a[le-1][1],e)) << "\n";
        }
    }
    return 0;
}