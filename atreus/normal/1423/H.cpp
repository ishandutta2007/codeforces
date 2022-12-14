#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 5e5 + 10;

int EOD[maxn];

int TASK[maxn], A[maxn], B[maxn], n, q;
vector<pii> tdo[4 * maxn];

struct DSU{
    int par[maxn];
    vector<int> rec;
    vector<pii> done;
    DSU(){
	memset(par, -1, sizeof par);
    }
    int fnd(int u){
	return par[u] < 0 ? u : fnd(par[u]);
    }
    int size(int u){
	u = fnd(u);
	return -par[u];
    }
    void mrg(int a, int b){
	a = fnd(a), b = fnd(b);
	if(a == b)
	    return;
	done.PB({a, par[a]});
	done.PB({b, par[b]});
	if(par[a] > par[b])
	    swap(a, b);
	par[a]+= par[b];
	par[b] = a;
    }
    void record(){
	rec.PB(sz(done));
    }
    void undo(){
	assert(sz(rec));
	int S = rec.back();
	rec.pop_back();
	while(sz(done) > S){
	    par[done.back().F] = done.back().S;
	    done.pop_back();
	}
    }
};DSU dsu;

vector<int> ret;

void add(int a, int b, int f, int s, int l = 0, int r = q, int id = 1){
    if(s <= l || r <= f)
	return;
    if(f <= l && r <= s){
	tdo[id].PB({a, b});
	return;
    }
    int mid = (l + r) >> 1;
    add(a, b, f, s, l, mid, 2*id);
    add(a, b, f, s, mid, r, 2*id+1);
}
void solve(int l = 0, int r = q, int id = 1){
    dsu.record();
    for(pii p : tdo[id])
	dsu.mrg(p.F, p.S);
    if(r-l == 1 && TASK[l] == 2){
	ret.PB(dsu.size(A[l]));	
    }
    int mid = (l+r) >> 1;
    if(r-l > 1){
	solve(l, mid, 2*id);
	solve(mid, r, 2*id+1);
    }
    dsu.undo();
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int k;
    cin >> n >> q >> k;
    int D = 0;
    fill(EOD, EOD + q + 5, q);
    for(int i = 0; i < q; i++){
	cin >> TASK[i];
	if(TASK[i] == 1){
	    cin >> A[i] >> B[i];
	}
	if(TASK[i] == 2){
	    cin >> A[i];
	}
	if(TASK[i] == 3){
	    EOD[D] = i;
	    D++;
	}
    }
    D = 0;
    for(int i = 0; i < q; i++){
	if(TASK[i] == 1){
	    add(A[i], B[i], i, D + k > q ? q : EOD[D + k - 1]);
	}
	if(TASK[i] == 3){
	    D++;
	}
    }
    solve();
    for(int x : ret){
	cout << x << "\n";
    }
    return 0;
}