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

typedef set<int> T;
typedef map<int,T> S;
int ans;

void dfs(S v[2]);

template<typename It>
int step(bool su, S &s, S &u, It sbegin, It send, It &it, T::iterator &subit) {
	if(it == send) return 0;
	++ subit;
	if(subit == it->second.end()) {
		int x = it->first;
		++ it;
		if(it != send) {
			if(abs(it->first - x) > 1) {
				S t(sbegin, it);
				S w;
				for(S::iterator jt = t.begin(); jt != t.end(); ++ jt) {
					s.erase(jt->first);
					for(T::iterator kt = jt->second.begin(); kt != jt->second.end(); ++ kt) {
						w[*kt].insert(jt->first);
						u[*kt].erase(jt->first);
						if(u[*kt].empty()) u.erase(*kt);
					}
				}
				S v[2];
				v[0].swap(t);
				v[1].swap(w);
				if(su) v[0].swap(v[1]);
				dfs(v);
				v[0].swap(s);
				v[1].swap(u);
				if(su) v[0].swap(v[1]);
				dfs(v);
				s.insert(t.begin(), t.end());
				for(S::iterator jt = t.begin(); jt != t.end(); ++ jt)
					for(T::iterator kt = jt->second.begin(); kt != jt->second.end(); ++ kt)
						u[*kt].insert(jt->first);
				return 2;
			}
			subit = it->second.begin();
		}
	}
	return 1;
}

void dfs(S v[2]) {
	/*
	cerr << "dfs:" << endl;
	each(i, v[0]) {
		cerr << i->first << ": [";
		each(j, i->second)
			cerr << (j == i->second.begin() ? "" : ", ") << *j;
		cerr << "], ";
	}
	cerr << endl;
	each(i, v[1]) {
		cerr << i->first << ": [";
		each(j, i->second)
			cerr << (j == i->second.begin() ? "" : ", ") << *j;
		cerr << "], ";
	}
	cerr << endl;
	*/
	S::iterator f[2]; T::iterator fsub[2];
	S::reverse_iterator b[2]; T::iterator bsub[2];
	rep(k, 2) {
		f[k] = v[k].begin();
		if(f[k] == v[k].end()) { cerr << "empty!" << endl; abort(); }
		fsub[k] = f[k]->second.begin();
		b[k] = v[k].rbegin();
		bsub[k] = b[k]->second.begin();
	}
	while(1) {
		int update = 0;
		if((update |= step(0, v[0], v[1], v[0].begin(), v[0].end(), f[0], fsub[0])) & 2) return;
		if((update |= step(1, v[1], v[0], v[1].begin(), v[1].end(), f[1], fsub[1])) & 2) return;
		if((update |= step(0, v[0], v[1], v[0].rbegin(), v[0].rend(), b[0], bsub[0])) & 2) return;
		if((update |= step(1, v[1], v[0], v[1].rbegin(), v[1].rend(), b[1], bsub[1])) & 2) return;
		if(!update) break;
	}
	++ ans;
}

int main() {
	int n;
	scanf("%d", &n);
	S v[2];
	rep(i, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[0][x].insert(y);
		v[1][y].insert(x);
	}
	ans = 0;
	dfs(v);
	printf("%d\n", ans);
	return 0;
}