    ///
    ///   Oh? You're approaching me?
    ///
     
    #include <bits/stdc++.h>
    #define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
    #define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
    #define Kill(x) exit((cout << (x) << '\n', 0))
    typedef long long ll;
    typedef std::pair<int,int> pii;
    typedef std::pair<ll,ll> pll;
    using namespace std;
     
    //#pragma GCC optimize("O3,unroll-loops")
    //#pragma GCC target("avx2")
     
    const int N = 100'032;;
    char col[N];
    int st[N], ft[N];
    vector<int> A[N];
    int n, q;
     
    void dfs1(int v, int& t){
    	st[v] = t++;
    	for(int u : A[v])
    		dfs1(u, t);
    	ft[st[v]] = t;
    }
     
    int main()
    {
    	cin.tie(0) -> sync_with_stdio(false);
    	cin >> n >> q;
    	Loop(i,1,n){
    		int p;
    		cin >> p;
    		A[p-1].push_back(i);
    	}
    	dfs1(0,*new int(0));
        asm("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop");
    	while(q--){
    		int t, v;
    		cin >> t >> v; v = st[v-1];
    		if(t==1){
    			Loop(i,v,ft[v]){
    				if(!col[i]){
    					col[i]=-1;
    					i=ft[i]-1;
    				}
    			}
    		}
    		if(t==2){
    			Loop(i,v,ft[v]) col[i] = 0;
    		}
    		if(t==3){
    			cout << (col[v]? "black\n": "white\n");
    		}
    	}
    }