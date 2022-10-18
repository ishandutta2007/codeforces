#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
#define int long long
using namespace std;

long long sum=0;
int n;
struct ST{
    vector<pair<pair<int,int>,int> > st;
    void init(int x){
        st.resize(4*x);
    }  
    void upd(int v,int a){
        st[v].fs.fs+=a;
        st[v].sc+=a;
    }
    void pudo(int v){
        upd(2*v+1,st[v].sc);
        upd(2*v+2,st[v].sc);
        st[v].sc=0;
    }
    void build(int v,int L,int R){
        if(L==R){
            cin >> st[v].fs.fs;
            sum+=st[v].fs.fs;
            st[v].fs.fs-=(n-1-L);
            st[v].fs.sc=L;
            return;
        }
        int m=(L+R)/2;
        build(2*v+1,L,m);
        build(2*v+2,m+1,R);
        st[v].fs=max(st[2*v+1].fs,st[2*v+2].fs);
    }   
    void update(int v,int L,int R,int l,int r,int k){
    	if(l>r){
    		return;
		}
        if(l==L && r==R){
            upd(v,k);
            return;
        }
        if(st[v].sc){
            pudo(v);
        }
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
        st[v].fs=max(st[2*v+1].fs,st[2*v+2].fs);
    }
    pair<int,int> query(){
        return st[0].fs;
    }
};
signed main(){
	AquA;
    int t;
    cin >> t;
    while(t--){
        sum=0;
        int k;
        cin >> n >> k;
        long long ans=0;
        ST st;
        st.init(n);
        st.build(0,0,n-1);
        //cout << "fwqjfeow" << endl;
        ans=sum;
        for(int i=0;i<k;i++){
            auto a=st.query();
            auto u=a.sc,p=a.fs;
            sum-=p;
            ans=min(ans,sum);
            st.update(0,0,n-1,u,u,-2e9);
            st.update(0,0,n-1,0,u-1,1);
            st.update(0,0,n-1,u+1,n-1,1);
        }
        cout << ans << "\n";
    }
	return 0;
}