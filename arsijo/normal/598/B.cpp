#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-10;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

#ifdef LOCAL
const int MAX = 1000;
#else
const int MAX = 2e5 + 1;
#endif

#define null NULL

set<ll> s;
ll get_rand() {
	ll ans;
	do {
		ans = 1LL * rand() * rand();
	} while (s.find(ans) != s.end());
	s.insert(ans);
	return ans;
}

struct node{
	int val, cnt;
	ll prior;
	node *l, *r;
	node(){
		val = prior = cnt = 0;
		l = r = null;
	}
	node(int val){
		this->val = val;
		prior = get_rand();
		cnt = 1;
		l = r = null;
	}
};

typedef node *_node;

int cnt(_node t){
	return (!t ? 0 : t->cnt);
}

void update(_node t){
	if(t)
		t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void split(_node t, _node &l, _node &r, int x, int sum = 0){
	if(!t)
		return void(l = r = null);
	int cur = sum + cnt(t->l);
	if(x <= cur){
		r = t;
		split(r->l, l, r->l, x, sum);
	}else{
		l = t;
		split(l->r, l->r, r, x, cur + 1);
	}
	update(l);
	update(r);
}

void merge(_node &t, _node l, _node r){
	if(!l || !r)
		return void(t = l ? l : r);
	if(l->prior > r->prior){
		t = l;
		merge(t->r, t->r, r);
	}else{
		t = r;
		merge(t->l, l, t->l);
	}
	update(t);
}


ostream& operator<<(ostream &out, _node t){
	if(!t)
		return out;
	out << t->l;
	out << t->val << " ";
	out << t->r;
	return out;
}

void print(_node t){
	if(!t)
		return;
	print(t->l);
	cout << (char) t->val;
	print(t->r);
}

void change(_node &t, int l, int r, int k){
	_node t1, t2, t3, t4;
	int len = r - l + 1;
	k %= len;
	split(t, t1, t2, l);
	split(t2, t2, t3, r - l + 1);
	split(t2, t2, t4, (len - k) % len);
	/*print(t1);
	cout << " ";
	print(t2);
	cout << " ";
	print(t4);
	cout << " ";
	print(t3);
	cout << endl;*/
	merge(t, t1, t4);
	merge(t, t, t2);
	merge(t, t, t3);
	//print(t);
	//cout << endl;
	update(t);
}

int main() {

	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	string s;
	cin >> s;

	_node root = new node(s[0]);
	for(int i = 1; i < (int) s.size(); i++) {
		merge(root, root, new node(s[i]));
	}

	int m;
	cin >> m;

	while(m--){
		int l, r, k;
		cin >> l >> r >> k;
		change(root, l - 1, r - 1, k);
	}

	print(root);

}