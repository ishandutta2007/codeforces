#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


using namespace std;
typedef long long ll;
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

struct Node{
	bool last;
	int childs[2];
	Node(){
		last = false;
		memset(childs,-1,sizeof(int) * 2);
	}
};

class trie_tree{

	vector<Node> nodes;

	int add_node(){
		nodes.push_back(Node());
		return sz(nodes) - 1;
	}

public:
	trie_tree(){
		clear();
	}

	void clear(){
		nodes.clear();
		add_node();
	}

	int add(const vector<char> &v){
		int cur = 0;
		for(int i = sz(v) - 1; i >= 0; i--){
			int nxt = nodes[cur].childs[v[i]];
			if(nxt == -1){
				nxt = add_node();
				nodes[cur].childs[v[i]] = nxt;
			}
			cur = nxt;
		}
		nodes[cur].last = true;
		return cur;
	}

	int add(const ll x){
		int cur = 0;
		for(int i = 41; i >= 0; i--){
			int v = (x >> i) & 1;
			int nxt = nodes[cur].childs[v];
			if(nxt == -1){
				nxt = add_node();
				nodes[cur].childs[v] = nxt;
			}
			cur = nxt;
		}
		nodes[cur].last = true;
		return cur;
	}
 

	ll check(const ll x){
		int cur = 0;
		ll ret = 0;
		for(int i = 41; i >= 0; i--){
			int v = (x >> i) & 1;
			int nxt = nodes[cur].childs[v];
			if(nxt == -1){
				nxt = nodes[cur].childs[1 - v];
				v = 1 - v;
			}
			ret = (ret << 1) ^ v;
			cur = nxt;
		}
		return ret;
	}
};

trie_tree trie;

int n;
ll a[ten(5) + 1];

int main(){
	cin>>n; 
	FOR(i,n) cin>>a[i];

	trie.add(0);
	ll cur = 0;
	FOR(i,n) cur ^= a[i];
	ll ans = cur;
	ll left = 0;

	for(int i = n-1; i >= 0; i--){
		const ll mx = (1LL << 42) - 1;
		cur ^= a[i];
		left ^= a[i];
		trie.add(left);
		ll ck = trie.check(mx ^ cur);
		ll cur_ans = cur ^ ck;
		ans = max(ans,cur_ans);
	}

	cout << ans << endl;

	return 0;
}