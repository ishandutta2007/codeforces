#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

struct ST{
    vector<vector<int> > st;
    void init(int x){
        st.resize(4*x);
    }
    void build(int v,int L,int R){
        if(L==R){
            st[v].resize(1);
            cin >> st[v][0];
            return;
        }
        int m=(L+R)/2;
        build(2*v+1,L,m);
        build(2*v+2,m+1,R);
        st[v].resize(min(64,R-L+1));
        merge(st[2*v+1].begin(),st[2*v+1].end(),st[2*v+2].begin(),st[2*v+2].end(),st[v].begin());
        if(st[v].size()>32){
        	st[v].resize(32);
		}
    }
    void query(int v,int L,int R,int l,int r,vector<int>& rt){
        if(l==L && r==R){
            vector<int> kk;
            kk.swap(rt);
            rt.resize(kk.size()+st[v].size());
            merge(kk.begin(),kk.end(),st[v].begin(),st[v].end(),rt.begin());
            if(rt.size()>32){
            	rt.resize(32);
			}
            return;
        }
        int m=(L+R)/2;
        if(r<=m){
            query(2*v+1,L,m,l,r,rt);
        }
        else if(l>m){
            query(2*v+2,m+1,R,l,r,rt);
        }
        else{
            query(2*v+1,L,m,l,m,rt);
            query(2*v+2,m+1,R,m+1,r,rt);
        }
    }
};
int main(){
	AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ST st;
        st.init(n);
        st.build(0,0,n-1);
        int q;
        cin >> q;
        for(int i=0;i<q;i++){
            vector<int> rt;
            int l,r;
            cin >> l >> r;
            l--;
            r--;
            st.query(0,0,n-1,l,r,rt);
            int ans=2e9;
            for(int j=0;j<rt.size();j++){
                for(int k=j+1;k<rt.size();k++){
                    ans=min(ans,rt[j]|rt[k]);
                }
            }
            cout << ans << "\n";
        }
    }
	return 0;
}