#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

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

const int INF = 1e9;
const int MAXN = 5e5 + 13;
const int MAXLGN = 20;
const int MAXSEG = 9*MAXN*MAXLGN/2;

int N;

struct node {
	node *l, *r;
	pii x  = mp(INF, -1);
} vals[MAXSEG]; int t = 0;
node* tree[4*MAXN];

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
	node* v = &vals[t++];
	if (lo == hi) {
        v->x = mp(n->x.f + x, i);
        return v;
    }
	int mid = (lo + hi) / 2;
	v->l = update(n->l, i, x, lo, mid);
	v->r = update(n->r, i, x, mid + 1, hi);
	v->x = min(v->l->x,v->r->x);
	return v;
}

pii query(node* n, int s, int e, int lo=0, int hi=-1) {
	if (hi == -1) hi = N - 1;
	if (hi < s || lo > e) return mp(INF, -1);
	if (lo >= s && hi <= e) return n->x;
	int mid = (lo + hi) / 2;
	return min(query(n->l, s, e, lo, mid),
			query(n->r, s, e, mid + 1, hi));
}
vi a;
vi loc [MAXN];
int index [5*MAXN];
/*int before(int idx){
    if(loc[a[idx]][0] == idx){
        return -1;
    }
    int l = 0;
    int r = loc[a[idx]].size() - 1;
    while(abs(l-r) >1 ){
        int m = (l + r)/2;
        if(loc[a[idx]][m] >= idx){
            r = m-1;
        }
        else{
            l = m;
        }
    }
    if(l>r){
        swap(l, r);
    }
    if(loc[a[idx]][r]<idx){
        return loc[a[idx]][r];
    }
    return loc[a[idx]][l];
}*/
int before[MAXN];
int main(){
    fast_io();
    int n;
 //   cin >> n;
    scanf("%d", &n);
    N = n;
    f0r(i, n){
        int ai;
        scanf("%d", &ai);
       // cin >> ai;
        a.eb(ai);
        if(loc[ai].size() == 0){
            before[i] = -1;
        }
        else{
            before[i] = loc[ai][loc[ai].size() - 1];
        }
        loc[ai].eb(i);
    }
    tree[0] = build_tree();
    int cur = 1;
    for (int i = 0; i < n; i++) {
        int b = before[i];
        if(b == -1){
            tree[cur] = update(tree[cur-1], i, -1 - INF);
            index[i] = cur;
            cur++;
        }
        else{
          //  tree[cur] = update(tree[cur-1], b, INF - query(tree[index[b]], b, b).f);
            tree[cur] = update(tree[cur-1], b, INF - before[index[b]]);
            cur++;
            tree[cur] = update(tree[cur-1], i, b - INF);
            index[i] = cur;
            cur++;
        }
	}
    int q;
    scanf("%d", &q);
   // cin >> q;
    f0r(testing, q){
        int l, r;
       // cin >> l >> r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        pii x = query(tree[index[r]], l, r);
        if(x.f<l){
      //      cout << a[x.s] << endl;
            //printf("%d", a[x.s]);
            printf("%d\n",a[x.s]);
        }
        else printf("%d\n",0);

    }
    return 0;
}