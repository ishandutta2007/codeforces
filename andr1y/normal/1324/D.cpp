#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout); FAST;
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL

using namespace std;
using namespace __gnu_pbds;
using python = void;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned short uss;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type> ordered_set;

const ll M = 1e9+7;
const ll N = 2e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
random_device rd;
mt19937 g1(rd());
mt19937 gen((rd()<<15)^(g1()<<7));
uniform_int_distribution<ll> uid(1, 1LL*rd()*rd());
struct Node{
	ll v= 0, x, y;
	Node *l = 0, *r = 0;
	Node(ll x) : x(x), y(uid(gen)), v(1){

	};
	void upd(){
		v = 1 + (l ? l->v : 0) + (r ? r->v : 0);
	}
};
//
Node* merge(Node *a, Node *b){
	if(!a) return b;
	if(!b) return a;
	if(a->y > b->y){
		Node *kk = merge(a->r, b);
		a->r = kk;
		a->upd();
		return a;
	}else{
		Node *kk = merge(a, b->l);
		b->l = kk;
		b->upd();
		return b;
	}
}

pair<Node*, Node*> split(Node *a, ll k){
	if(!a) return {0, 0};
	if(a->x <= k){
		auto pp = split(a->r, k);
		a->r = pp.x;
		a->upd();
		return {a, pp.y};
	}else{
		auto pp = split(a->l, k);
		a->l = pp.y;
		a->upd();
		return {pp.x, a};
	}
}
Node *root = nullptr;
void insert(ll x){
	Node *a = new Node(x);
	auto p = split(root, x);
	root = merge(p.x, merge(a, p.y));
}
ll lessthan(ll k){
	auto p1 = split(root, k-1);
	ll ans = (p1.x ? p1.x->v : 0);
	root = merge(p1.x, p1.y);
	return ans;
}
ll a[N], b[N];
python solve(){
	FAST;
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++) cin >> a[i];
	for(ll i = 0;i<n;i++) cin >> b[i];
	ll ans = 0;
	for(ll i = 0;i<n;i++){
		ans += lessthan(a[i]-b[i]);
		insert(b[i]-a[i]);
	}
	cout << ans << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}