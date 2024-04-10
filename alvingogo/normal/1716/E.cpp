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
        int pre=-1e18,suf=-1e18,sum=0,mx=0;
    };
    vector<vector<no> > st;
    void init(int x){
        st.resize(4*x);
    }
    no merge(no a,no b){
        no c;
        c.pre=max(a.pre,a.sum+b.pre);
        c.suf=max(b.suf,b.sum+a.suf);
        c.sum=a.sum+b.sum;
        c.mx=max({c.mx,a.mx,b.mx,a.suf+b.pre});
        return c;
    }
    void build(int v,int L,int R){
        st[v].resize(R-L+1);
        if(L==R){
            st[v].resize(1);
            cin >> st[v][0].pre;
            st[v][0].suf=st[v][0].mx=st[v][0].sum=st[v][0].pre;
            return;
        }
        int m=(L+R)/2;
        build(2*v+1,L,m);
        build(2*v+2,m+1,R);
        for(int i=0;i<(R-L+1)/2;i++){
            st[v][i]=merge(st[2*v+1][i],st[2*v+2][i]);
            st[v][i+(R-L+1)/2]=merge(st[2*v+2][i],st[2*v+1][i]);
        }
    }
};
signed main(){
    AquA;
    int n;
    cin >> n;
    ST st;
    st.init(1<<n);
    st.build(0,0,(1<<n)-1);
    int q;
    cin >> q;
    int nw=0;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        nw^=(1<<x);
        cout << st.st[0][nw].mx << "\n";
    }
    return 0;
}