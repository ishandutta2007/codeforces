#include <bits/stdc++.h>
using namespace std;
long double PI = acos(-1);
long double DEL = 1e-12;
long long M =  1e9 + 7;
const long long N = 3e5 + 10;
#define ftt cin>>tc;for(int cas=1;cas<=tc;++cas)
#define all(a) a.begin(),a.end()
#define sq(a) ((a)*(a))
#define double long double
#define dbg cout<<"\nhi\n";
#define int long long
#define nl cout<<"\n"
#define sp <<" "<<
#define mid ((l+r)>>1)
#define rson 2*i+1
#define lson 2*i
#define X real()
#define Y imag()


//*********************************** CHECK CONSTRAINTS ***********************************
int cnt, sum, mx, mn, ans, a[N], b[N];
int n, m, d, i, j, k, l, p, q, r, t, w, x, y, z, tc;
string s;



//************************************* CODE STARTS ****************************************

struct HEAVY_LIGHT{
        vector<int> dfsarray,depth,heavy,par,sub,head,pos,seg;
        
        void buildseg(int i,int l,int r){
                if(l == r){
                        seg[i] = a[dfsarray[l]];
                        return;
                }
                buildseg(lson,l,mid);
                buildseg(rson,mid+1,r);
                seg[i] = seg[lson] + seg[rson];
        }
        
        void upd(int x,int v,int i = 1,int l = 0,int r = n - 1){
                if(x < l or x > r){
                        return;
                }
                if(l == r){
                        seg[i] = v;
                        return;
                }
                upd(x,v,lson,l,mid);
                upd(x,v,rson,mid+1,r);
                seg[i] = seg[lson] + seg[rson];
        }
        
        int query(int a,int b,int i = 1,int l = 0,int r = n - 1){
                if(l > b or r < a){
                        return 0;
                }
                if(a <= l and r <= b){
                        return seg[i];
                }
                return query(a,b,lson,l,mid) + query(a,b,rson,mid+1,r);
        }
        
        void build(vector<vector<int>> &g,int root){
                int sz = n;
                depth.resize(sz + 1);
                heavy.resize(sz + 1);
                par.resize(sz + 1);
                pos.resize(sz + 1);
                head.resize(sz + 1);
                sub.resize(sz + 1);
                seg.resize(4 * sz + 1);
                dfs(root,root,g);
                decompose(root,root,g);
                buildseg(1,0,n - 1);
        }
        
        void dfs(int i,int p,vector<vector<int>> &g){
                depth[i] = depth[p] + 1;
                par[i] = p;
                sub[i] = 1;
                int ms = 0,hc = -1;
                for(auto j:g[i]){
                        if(j == p)continue;
                        dfs(j,i,g);
                        sub[i] += sub[j];
                        if(sub[j] > ms){
                                ms = sub[j];
                                hc = j;
                        }
                }
                heavy[i] = hc;
        }
        
        void decompose(int i,int h,vector<vector<int>> &g){
                pos[i] = dfsarray.size();
                dfsarray.push_back(i);
                head[i] = h;
                
                if(heavy[i] != -1){
                        decompose(heavy[i],h,g);
                }
                
                for(auto j:g[i]){
                        if(j == par[i] or j == heavy[i])continue;
                        decompose(j,j,g);
                }
        }
        
        int lca(int u,int v){           // O(logN)
                for(;head[u] != head[v];u = par[head[u]]){
                        if(depth[head[u]] < depth[head[v]]){
                                swap(u,v);
                        }
                }
                return depth[u] > depth[v] ? v : u;
        }
        
        int get(int u,int v){
                int ans = 0;
                int sub = a[u] + a[v];
                for(;head[u] != head[v];u = par[head[u]]){
                        if(depth[head[u]] < depth[head[v]]){
                                swap(u,v);
                        }
                        ans += query(pos[head[u]],pos[u]);
                }
                if(depth[u] > depth[v]){
                        swap(u,v);
                }
                ans += query(pos[u],pos[v]);
                ans *= 2;
//                cout << ans sp
                return ans - sub;
        }
};

vector<vector<int>> g;

int32_t main()
{
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
        freopen("/Users/jenish/XCode/cp/input.txt","r",stdin);
#endif
        cin >> n >> q;
        for(int i = 1;i <= n;i++){
                cin >> a[i];
                a[i] = abs(a[i]);
        }
        g.resize(n + 1);
        for(int i = 1;i < n;i++){
                cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        
        HEAVY_LIGHT h;
        h.build(g, 1);
        
        while(q--){
                cin >> t >> x >> y;
                if(t == 1){
                        h.upd(h.pos[x],abs(y));
                        a[x] = abs(y);
                }
                else{
                        cout << h.get(x,y);nl;
                }
        }
}