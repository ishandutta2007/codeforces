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
	int childs[26];
	Node(){
		memset(childs,-1,sizeof(int) * 26);
	}
};

bool vailds[2000];
int k;

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

	int size() const { return sz(nodes) - 1; }

	int add(const char* s,int idx){
		int cur = 0;
		int sm = 0;
		for(int i = idx; s[i] && sm + vailds[i] <= k; sm += vailds[i++]){
			int nxt = nodes[cur].childs[s[i] - 'a'];
			if(nxt == -1){
				nxt = add_node();
				nodes[cur].childs[s[i] - 'a'] = nxt;
			}
			cur = nxt;
		}
		return cur;
	}

	void check(const char* s,int idx){
		int cur = 0;
		int sm = 0;
		for(int i = idx; s[i] && sm + vailds[i] <= k; sm += vailds[i++]){
			int nxt = nodes[cur].childs[s[i] - 'a'];
			if(nxt == -1) break;
			cur = nxt;
		}
		add(s,idx);
	}
};


string s,vaild;

int main(){
	 cin>>s>>vaild>>k;
	FOR(i,sz(s)) vailds[i] = (vaild[s[i] - 'a'] - '0' == 0);

	trie_tree tr;

	FOR(i,sz(s)){		
		tr.check(s.c_str(),i);
	}
	cout << tr.size() << endl;

	return 0;
}