#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
#define int long long
using namespace std;

struct ST{
    vector<int> st;
    void init(int x){
        st.resize(4*x,-1e15);
    }
    void update(int v,int L,int R,int pos,int x){
        if(L==R){
            st[v]=max(st[v],x);
            return;
        }
        int m=(L+R)/2;
        if(pos<=m){
            update(2*v+1,L,m,pos,x);
        }
        else{
            update(2*v+2,m+1,R,pos,x);
        }
        st[v]=max(st[2*v+1],st[2*v+2]);
    }
    int query(int v,int L,int R,int l,int r){
        if(r<l || R<l || r<L){
            return -1e15;
        }
        if(L==l && r==R){
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
};
int sign(int x){
    return (x==0)?0:((x>0)?1:-1);
}
signed main(){
	AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n+1),dp(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            v[i]+=v[i-1];
        }
        vector<int> p=v;
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        for(int i=0;i<=n;i++){
            v[i]=lower_bound(p.begin(),p.end(),v[i])-p.begin();
        }
        ST st,st2,st3;
        int z=p.size();
        st.init(z);
        st.update(0,0,z-1,v[0],0);
        st2.init(z);
        st2.update(0,0,z-1,v[0],0);
        st3.init(z);
        st3.update(0,0,z-1,v[0],0);
        for(int i=1;i<=n;i++){
            dp[i]=st2.query(0,0,z-1,0,v[i]-1)+i;
            dp[i]=max(dp[i],st.query(0,0,z-1,v[i],v[i]));
            dp[i]=max(dp[i],st3.query(0,0,z-1,v[i]+1,z-1)-i);
            st.update(0,0,z-1,v[i],dp[i]);
            st2.update(0,0,z-1,v[i],dp[i]-i);
            st3.update(0,0,z-1,v[i],dp[i]+i);
        }
        cout << dp[n] << "\n";
    }
	return 0;
}