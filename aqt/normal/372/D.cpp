#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, n;
};

int N, K;
vector<int> graph[100005];
set<int> lftst, rhtst;
int tbl[20][100005];
int dep[100005];
Node seg[400005];
int BIT[200005];
int lft[100005], rht[100005], t, et[200005];

void dfs(int n){
    lft[n] = ++t;
    et[t] = n;
    for(int e : graph[n]){
        if(e != tbl[0][n]){
            tbl[0][e] = n;
            dep[e] = dep[n] + 1;
            dfs(e);
        }
    }
    rht[n] = ++t;
    et[t] = n;
}

int lca(int u, int v){
    if(dep[u] < dep[v]){
        swap(u, v);
    }
    for(int d = 19; d>=0; d--){
        if(dep[tbl[d][u]] >= dep[v]){
            u = tbl[d][u];
        }
    }
    if(u == v){
        return u;
    }
    for(int d = 19; d>=0; d--){
        if(tbl[d][u] != tbl[d][v]){
            u = tbl[d][u];
            v = tbl[d][v];
        }
    }
    return tbl[0][u];
}

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    if(seg[idx].l == seg[idx].r){
        seg[idx].n = l;
        return;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    seg[idx].n = lca(seg[2*idx].n, seg[2*idx+1].n);
}

int query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].n;
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else{
        return lca(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
    }
}

void upd(int p, int v){
    for(int i = p; i<=2*N; i+=i&-i){
        BIT[i] += v;
    }
}

int query(int p){
    int ret = 0;
    for(int i = p; i; i-=i&-i){
        ret += BIT[i];
    }
    return ret;
}

int solve(int n){
    int opt1 = 0, opt2 = 0;
    if(!(query(rht[n]-1) - query(lft[n]))){
        if(et[*lftst.begin()] != n){
            opt1 = lca(n, et[*(--lftst.lower_bound(lft[n]))]);
        }
        if(et[*(--rhtst.end())] != n){
            //cout << "hello" << et[*rhtst.upper_bound(rht[n])] << " " << n << endl;
            opt2 = lca(n, et[*rhtst.upper_bound(rht[n])]);
        }
    }
    int mini = INT_MAX;
    if(opt1){
        mini = min(mini, dep[n]-dep[opt1]);
    }
    if(opt2){
        mini = min(mini, dep[n]-dep[opt2]);
    }
    //cout << opt1 << " " << opt2 << endl;
    if(mini == INT_MAX){
        mini = 0;
    }
    //cout << "mini: " << mini << endl;
    return mini;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dep[1] = 1;
    dfs(1);
    for(int d = 1; d<20; d++){
        for(int n = 1; n<=N; n++){
            tbl[d][n] = tbl[d-1][tbl[d-1][n]];
        }
    }
    build(1, N, 1);
    int tot = 1, ans = 0;
    for(int l = 1, r = 1; r<=N; r++){
        int crntlca = query(l, r, 1);
        //cout << l << " " << r << " " << crntlca << endl;
        upd(rht[r], 1);
        rhtst.insert(rht[r]);
        lftst.insert(lft[r]);
        int lstlca = 1;
        if(l != r){
            lstlca = query(l, r-1, 1);
        }
        //cout << "lca: " << r << " " << lstlca << " " << crntlca << endl;
        if(dep[crntlca] < dep[lstlca]){
            tot += dep[lstlca] - dep[crntlca];
            tot += dep[r] - dep[crntlca];
        }
        else{
            tot += solve(r);
        }
        //cout << r << endl;
        while(tot > K){
            //cout << "in while: " << tot << " " << l << " " << r << endl;
            lstlca = crntlca;
            crntlca = query(l+1, r, 1);
            tot -= solve(l);
            tot -= dep[crntlca] - dep[lstlca];
            upd(rht[l], -1);
            lftst.erase(lft[l]);
            rhtst.erase(rht[l]);
            l++;
        }
        //cout << "end: " << l << " " << r << " " << tot << endl;
        ans = max(ans, r-l+1);
    }
    cout << ans << endl;
}