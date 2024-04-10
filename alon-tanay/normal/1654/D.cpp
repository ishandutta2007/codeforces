#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
#define pi pair<int,int>
#define Event pair<pi,pi>
#define f first
#define s second

using namespace std;

struct Seg {
    vector<int> seg;
    int n;
    Seg(int n): n(n) {
        seg.resize(2*n);
    }
    int sum(int a, int b) {
        int res = 0;
        for(a += n, b += n; a < b; a >>= 1, b>>=1) {
            if(a&1) {
                res += seg[a++];
            }
            if(b&1) {
                res += seg[--b];
            }
        }
        return res;
    }
    void add(int i, int x) {
        i += n;
        seg[i] += x;
        for(i >>= 1; i; i >>= 1) {
            seg[i] = seg[i<<1] + seg[(i<<1)|1];
        }
    }
    void set(int i, int x) {
        i += n;
        seg[i] = x;
        for(i >>= 1; i; i >>= 1) {
            seg[i] = seg[i<<1] + seg[(i<<1)|1];
        }
    }
};

ll pw(ll b, ll e) {
    if(e == 0) { return 1LL;} 
    if(e&1) {
        return (b*pw((b*b)%MOD,e/2))%MOD;
    }
    return pw((b*b)%MOD,e/2);
}

vector<vector<int>> nei;
vector<int> loc;
vector<int> sub;
vector<ll> DIF;

int idx = 1;
int dfs(int node, int par = -1) {
    loc[node] = idx;
    int cur_sz = 1;
    for(int ne : nei[node]) {
        if(ne == par) { continue; }
        idx ++;
        cur_sz += dfs(ne,node);
    }
    return sub[node] = cur_sz;
}

ll total = 0;
void get_total(int node, ll cur = 1, int par = -1) {
    cur = (cur*DIF[node]) % MOD;
    total = (total + cur) %MOD;
    for(int ne : nei[node]) {
        if(ne == par) { continue; }
        get_total(ne,cur,node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> prime(200002,MOD);
    for(int i = 2; i < 200002; i ++) {
        if(prime[i] == MOD) {
            prime[i] = i;
            ll j = i;
            for(j *= i; j < 200002; j += i) {
                prime[j] = min(prime[j],i);
            }
        }
    }

    int t;
    cin >> t;
    while(t--) {
        idx = 1;
        int n; 
        cin >> n;
        nei.clear();
        nei.resize(n+1);
        loc.clear();
        loc.resize(n+1);
        sub.clear();
        sub.resize(n+1);
        DIF.clear();
        DIF.resize(n+1,1);
        vector<vector<int>> input(n-1);
        for(int i = 1; i < n; i ++) {
            int x,y,a,b;
            cin >> a >> b >> x >> y;
            nei[a].push_back(b);
            nei[b].push_back(a);
            input[i-1] = {x,y,a,b};
        }
        dfs(1);
        deque<int> bfs = {1};
        vector<int> depth(n+1);
        depth[1] = 1;
        while(bfs.size()) {
            int cur = bfs.back();
            bfs.pop_back();
            for(int ne : nei[cur]) {
                if(!depth[ne]) {
                    depth[ne] = depth[cur] + 1;
                    bfs.push_back(ne);
                }
            }
        }
        vector<vector<Event>> ev(n+1);
        for(vector<int> &in : input) {
            int x = in[0],y = in[1],a = in[2],b = in[3];
            int ev_depth = min(depth[a],depth[b]);
            int aa = a;
            int bb = b;
            if(depth[a] > depth[b]) {
                swap(aa,bb);
            }
            int gcd = __gcd(x,y);
            x /= gcd;
            y /= gcd;
            while(x > 1) {
                int p = prime[x];
                int cnt = 0;
                while((x%p)==0) {
                    cnt ++;
                    x /= p;
                }
                int dif = cnt * (depth[a]-depth[b]);
                // cout << p << ": " << dif << endl;
                ev[p].push_back({{ev_depth,aa},{bb,dif}});
            }
            while(y > 1) {
                int p = prime[y];
                int cnt = 0;
                while((y%p)==0) {
                    cnt ++;
                    y /= p;
                }
                int dif = cnt * (depth[b]-depth[a]);
                // cout << p << "| " << dif << endl;
                ev[p].push_back({{ev_depth,aa},{bb,dif}});
            }
        }

        Seg seg(n+1);
        total = 0;
        ll st = 1;
        for(int i = 2; i <= n; i ++) {
            if(prime[i] == i && !ev[i].empty()) {
                // cout << i << "!" << endl;
                sort(ev[i].begin(), ev[i].end());
                int mx = 0, mn = 0;
                for(Event e : ev[i]) {
                    int b = e.s.f;
                    int dif = e.s.s;
                    int cur = seg.sum(0,loc[b]) + dif;
                    // cout << "??" << loc[b] << endl;
                    // cout << " " << b << " " << dif << " | " << cur << endl;
                    mn = min(mn,cur);
                    seg.add(loc[b]-1,dif);
                    seg.add(loc[b]-1+sub[b],-dif);
                }
                // cout << mn << endl;
                for(Event e : ev[i]) {
                    int b = e.s.f;
                    int dif = e.s.s;
                    if(dif >= 0) {
                        DIF[b] = (DIF[b] * pw(i,dif)) % MOD;
                    } else {
                        DIF[b] = (DIF[b] * pw(i,MOD-1+dif)) % MOD;
                    }
                }

                for(Event e : ev[i]) {
                    int b = e.s.f;
                    seg.set(loc[b]-1,0);
                    seg.set(loc[b]-1+sub[b],0);
                }
                st = (st*pw(i,-mn))%MOD;
                
            }
        }
        total = 0;
        get_total(1,st);
        cout << total << "\n";
    }
    return 0;
}