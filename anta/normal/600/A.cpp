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
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	string s;
	while(cin >> s) {
		vector<string> v;
		size_t i = 0, j;
		v.clear();
		while(1) {
			j = i;
			while(j != s.size() && (isalnum(s[j]) || s[j] == '.')) ++ j;
			v.push_back(s.substr(i, j-i));
			if(j == s.size()) break;
			i = j+1;
		}
		string a, b;
		int aa = 0, bb = 0;
		for(const string &s : v) {
			bool ok = true;
			for(char c : s)
				ok &= isdigit(c) != 0;
			ok &= !s.empty() && (s.size() == 1 || s[0] != '0');
			if(ok) {
				if(aa ++ > 0) a += ',';
				a += s;
			} else {
				if(bb ++ > 0) b += ',';
				b += s;
			}
		}
		if(aa == 0)
			puts("-");
		else
			printf("\"%s\"\n", a.c_str());
		if(bb == 0)
			puts("-");
		else
			printf("\"%s\"\n", b.c_str());
	}
	return 0;
}