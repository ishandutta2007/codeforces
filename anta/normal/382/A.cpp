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
#include <list>
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

int main() {
	string s, x, y, z;
	cin >> s;
	x = s.substr(0, s.find('|'));
	y = s.substr(s.find('|')+1);
	cin >> z;
	int a = x.size(), b = y.size(), c = z.size();
	const char *imp = "Impossible";
	if(a == b) {

	}else if(a < b) {
		int t = b - a;
		if(t > c) {
			puts(imp);
			return 0;
		}
		x += z.substr(0, t);
		z = z.substr(t);
	}else if(a > b) {
		int t = a - b;
		if(t > c) {
			puts(imp);
			return 0;
		}
		y += z.substr(0, t);
		z = z.substr(t);
	}
	if(z.size() % 2 != 0) {
		puts(imp);
		return 0;
	}
	x += z.substr(0, z.size() / 2);
	y += z.substr(z.size() / 2);
	cout << x << "|" << y << endl;
	return 0;
}