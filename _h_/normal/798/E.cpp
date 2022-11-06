#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct ST {
    int n;
    vector<pii> t;
    ST(int n) : n(n) {
        t.resize(2*n);
    }
    
    void build(){
        rrep(i,1,n) t[i] = max(t[2*i], t[2*i+1]);
    }    
    void upd(int pos){
        t[pos += n] = {-1, 0};
        while(pos /= 2) t[pos] = max(t[2*pos], t[2*pos+1]);
    }
    pii que(int l, int r){
        pii ans(-1,0);
        for(l += n, r += n; l < r; l /= 2, r /= 2){
            if(l&1) ans = max(ans, t[l++]);
            if(r&1) ans = max(ans, t[--r]);
        }
        return ans;
    }
        
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
    cin >> n;
    vi as(n);
    trav(x, as) cin >> x;
    trav(x, as) --x;
    trav(x,as) if(x == -2) x = n;
    
    ST st(n);
    rep(i,0,n) st.t[i+n] = {as[i], i};
    st.build();
    
    vi inv(n+1, n);
    rep(i,0,n) inv[as[i]] = i;
    
    vi ans(n,-1);
    int ix = n-1;
    
    function<void(int)> calc = [&](int i){
        st.upd(i);
        
        if(as[i] != n && ans[as[i]]==-1) calc(as[i]);
        
        int j = inv[i];
        while(true){
            pii pa = st.que(0, j);
            if(pa.first != -1) assert(as[pa.second] == pa.first);
            if(pa.first <= i) break;
            else calc(pa.second);
        }
        ans[i] = ix--;
    };
    rep(i,0,n) if(ans[i] == -1) calc(i);
    
    trav(x, ans) cout << x+1 << ' ';
    cout << endl;
}