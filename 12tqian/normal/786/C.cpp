#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

const double PI = 4 * atan(1);

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define pd pair<double, double>

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
const int MAX = 1e5+5;
const int INF = 1e9;
const int MAXN = 1e5 + 13;
const int MAXLGN = 18;
const int MAXSEG = 5*MAXN*MAXLGN;

int N;

struct node {
	node *l, *r;
	int x;
} vals[MAXSEG]; int t = 0;
node* tree[5*MAXN];

node* build_tree(int lo=0, int hi=-1) {
	if (hi == -1) hi = N - 1;
	node* cur = &vals[t++];
	if (lo != hi) {
		int mid = (lo + hi) / 2;
		cur->l = build_tree(lo, mid);
		cur->r = build_tree(mid + 1, hi);
	}
	return cur;
}

node* update(node* n, int i, int x, int lo=0, int hi=-1) {
	if (hi == -1) hi = N - 1;
	if (hi < i || lo > i) return n;
	assert(t<MAXSEG);
	node* v = &vals[t++];
	if (lo == hi) { v->x = n->x + x; return v; }
	int mid = (lo + hi) / 2;
	v->l = update(n->l, i, x, lo, mid);
	v->r = update(n->r, i, x, mid + 1, hi);
	v->x = v->l->x + v->r->x;
	return v;
}
int query(node* n, int s, int e, int lo=0, int hi=-1) {
	if (hi == -1) hi = N - 1;
	if (hi < s || lo > e) return 0;
	if (lo >= s && hi <= e) return n->x;
	int mid = (lo + hi) / 2;
	return query(n->l, s, e, lo, mid) +
			query(n->r, s, e, mid + 1, hi);
}
int query1(node* a, int lo, int hi, int k){
    if(lo == hi){
        return lo;
    }
    int m = (lo + hi)/2;
    int cnt = a->l->x;
    if(cnt >= k){
        return query1(a->l, lo, m, k);
    }
    return query1(a->r, m+1, hi, k-cnt);
}
int query2(node* a, int l, int r, int k){
    return query1(a, l, r, k);
}


vi a;
int current[MAX];
vi colors[MAX];
int st [MAX];
vi init;
int main(){
    fast_io();
    int n;
    cin >> n;
    N = n;
    f0r(i, n){
        int d;
        cin >> d;
        d--;
        a.eb(d);
        colors[d].eb(i);
    }
    f0r(i, n){
        if(current[a[i]] == 0){
            st[i] = 1;
            current[a[i]]++;
        }
    }
    tree[0] = build_tree();
    f0r(i, n){
        tree[i+1] =  update(tree[i], i, st[i]);
    }
    int cur = n;
    f1r(i,1, n+1){
        if(current[a[i-1]] >= sz(colors[a[i-1]])){
            tree[cur+1] = update(tree[cur], i-1, -1); cur++;
            tree[cur+1] = update(tree[cur], i-1, 0); cur++;
        }
        else{
            tree[cur+1] = update(tree[cur], i-1, -1); cur++;
            tree[cur+1] = update(tree[cur], colors[a[i-1]][current[a[i-1]]], 1); cur++;
            current[a[i-1]]++;
        }
    }
    f1r(k, 1, n+1){
        int cnt = 0;
        int curr = 0;
        while(true){
            int v1;
            int loc;
           // assert(n+ 2*curr<MAXSEG);
            if(cur == 0){
                v1 = 0;
            }
            else{
                v1 = query(tree[n+  2*curr], 0, curr-1);;
            }
            int v2 = query(tree[n + 2*curr], curr, n-1);
            if(v2<=k){
                loc = n-1;
                cnt++;
                break;
            }
            loc = query2(tree[n + 2*curr], 0, n-1, v1+k+1);
            cnt++;
            curr = loc;
        }
        cout << cnt << endl;
    }
    return 0;
}