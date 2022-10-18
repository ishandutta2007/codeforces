#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
#define int long long
using namespace std;

typedef pair<int,int> pii;
const int mod=1e9+7;
int add(int x,int y){
    return ((x+y)%mod+mod)%mod;
}
int mul(int x,int y){
    return (1ll*x*y%mod+mod)%mod;
}
struct ST{
    vector<pii> st;
    void init(int nn){
        st.resize(4*nn);
    }
    void update(int v,int L,int R,int pos,pii k){
        if(L==R){
            st[v].fs=add(st[v].fs,k.fs);
            st[v].sc=add(st[v].sc,k.sc);
            return;
        }
        int m=(L+R)/2;
        if(pos<=m){
            update(2*v+1,L,m,pos,k);
        }
        else{
            update(2*v+2,m+1,R,pos,k);
        }
        st[v].fs=add(st[2*v+1].fs,st[2*v+2].fs);
        st[v].sc=add(st[2*v+1].sc,st[2*v+2].sc);
    }
    pii query(int v,int L,int R,int l,int r){
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
            pii a=query(2*v+1,L,m,l,m),b=query(2*v+2,m+1,R,m+1,r);
            return {add(a.fs,b.fs),add(a.sc,b.sc)};
        }
    }
};
struct qu{
    int l,r;
    int id;
};  
struct ds{
    int a,b;
    int id;
};
signed main(){
	AquA;
    int n,q;
    cin >> n >> q;
    vector<int> a(n),b(n);
    vector<ds> h(n-1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(i){
            b[i]+=b[i-1];
        }
    }
    for(int i=0;i<n-1;i++){
        h[i].a=a[i+1]-a[i];
        h[i].id=i;
        h[i].b=b[i];
    }
    ST s1,s2;
    s1.init(n);
    s2.init(n);
    vector<qu> vq(q);
    for(int i=0;i<q;i++){
        cin >> vq[i].l >> vq[i].r;
        vq[i].l--;
        vq[i].r--;
        vq[i].id=i;
    }
    auto get=[&](int c){
        return (c==0?0:b[c-1]);
    };
    sort(vq.begin(),vq.end(),[&](qu x,qu y){return get(x.l)<get(y.l);});
    sort(h.begin(),h.end(),[&](ds c,ds d){return c.b<d.b;});
    int l=0;
    vector<int> ans(q);
    for(int i=0;i<n;i++){
        int z=h[i].id;
        s1.update(0,0,n-1,z,{mul(h[i].a,h[i].b%mod),h[i].a});
    }
    for(int i=0;i<q;i++){
        while(l<n && h[l].b<get(vq[i].l)){
            int z=h[l].id;
            s1.update(0,0,n-1,z,{mul(-h[l].a,h[l].b%mod),-h[l].a});
            s2.update(0,0,n-1,z,{mul(h[l].a,h[l].b%mod),h[l].a});
            l++;
        }
        pii c=s1.query(0,0,n-1,vq[i].l,vq[i].r-1);
        pii d=s2.query(0,0,n-1,vq[i].l,vq[i].r-1);
        ans[vq[i].id]=add(add(c.fs,mul(-c.sc,get(vq[i].l)%mod)),add(-d.fs,mul(d.sc,get(vq[i].l)%mod)));
    }
    for(auto h:ans){
        cout << h << "\n";
    }
	return 0;
}