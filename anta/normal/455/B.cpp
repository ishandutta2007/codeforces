#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct Node {
	Node *next[26];
	Node() {
		mset(next, 0);
	}
};

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	const int M = 100000;
	char *s = new char[M+1];
	vector<Node> nodes(M+1); int m = 0;
	Node *root = &nodes[m ++];
	rep(i, n) {
		scanf("%s", s);
		Node *t = root;
		for(const char *p = s; *p; ++ p) {
			int c = *p - 'a';
			if(t->next[c] == NULL)
				t->next[c] = &nodes[m ++];
			t = t->next[c];
		}
	}
	vector<bool> dp1(m), dp2(m);
	for(int i = m-1; i >= 0; i --) {
		bool x, y;
		const Node *t = &nodes[i];
		if(count(t->next, t->next + 26, (const Node*)NULL) == 26) {
			x = false, y = true;
		}else {
			x = false, y = false;
			rep(a, 26) if(t->next[a]) {
				x |= !dp1[t->next[a] - &nodes[0]];
				y |= !dp2[t->next[a] - &nodes[0]];
			}
		}
//		cerr << i << ": " << x << ", " << y << endl;
		dp1[i] = x;
		dp2[i] = y;
	}
	bool x = dp1[0], y = dp2[0];
//	cerr << x << ", " << y << endl;
	//x : 1swap
	//y : 1
	bool ans;
	if(!x && !y) ans = false;			//(k-1)
	else if(x && !y) ans = k % 2 == 1;	//
	else if(!x && y) ans = false;		//
	else ans = true;					//(k-1)
	puts(ans ? "First" : "Second");
	return 0;
}