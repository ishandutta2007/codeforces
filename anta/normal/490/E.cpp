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
#include <functional>
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

char s[10];
string p;

char memo[11][2];
char rec(int i, bool gt) {
	if(s[i] == 0) return gt;
	char &r = memo[i][gt];
	if(r != -1) return r;
	r = 0;
	char c = p[i], d = s[i];
	if(d != '?') {
		if(gt || c <= d)
			r |= rec(i+1, gt || c < d);
	}else {
		char z = i == 0 ? '1' : '0';
		if(gt || c <= z) r |= rec(i+1, gt || c < z);
		r |= rec(i+1, gt);
		if(c != '9') r |= rec(i+1, true);
	}
	return r;
}

void rec_huku(int i, bool gt) {
	if(s[i] == 0) return;
	char c = p[i], d = s[i];
	if(d != '?') {
		if(gt || c <= d) {
			if(rec(i+1, gt || c < d)) {
				return rec_huku(i+1, gt || c < d);
			}
		}
	}else {
		char z = i == 0 ? '1' : '0';
		if(gt || c <= z) {
			if(rec(i+1, gt || c < z)) {
				s[i] = z;
				return rec_huku(i+1, gt || c < z);
			}
		}
		if(rec(i+1, gt)) {
			s[i] = c;
			return rec_huku(i+1, gt);
		}
		if(c != '9') {
			if(rec(i+1, true)) {
				s[i] = c+1;
				return rec_huku(i+1, true);
			}
		}
	}
	cerr << "err!" << endl;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<string> ans(n);
	rep(i, n) {
		scanf("%s", s);
		int len = strlen(s);
		p = i == 0 ? "0" : ans[i-1];
		bool ok;
		if(len > (int)p.size()) {
			ok = true;
			rep(i, len)
				if(s[i] == '?')
					s[i] = i == 0 ? '1' : '0';
		}else if(len < (int)p.size()) {
			ok = false;
		}else {
			mset(memo, -1);
			if(rec(0, false) == 0) {
				ok = false;
			}else {
				ok = true;
				rec_huku(0, false);
			}
		}
		if(!ok) {
			puts("NO");
			return 0;
		}
		ans[i] = s;
	}
	puts("YES");
	rep(i, n)
		puts(ans[i].c_str());
	return 0;
}