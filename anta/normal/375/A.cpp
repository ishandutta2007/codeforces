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
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

string ok[7][7];
char a[1000001];
int cnt[10];
int main() {
	char t[4] = {1,6,8,9};
	sort(t, t+4);
	rep(yy, 7) {
		do {
			int x = 0, y = yy;
			string s;
			rep(i, 4) {
				x = (x + y * t[i]) % 7;
				s += char('0' + t[i]);
				y = y * 10 % 7;
			}
			ok[yy][x] = s;
		}while(next_permutation(t,t+4));
	}

	scanf("%s", a);
	int n = strlen(a);
	rep(i, n) cnt[a[i]-'0'] ++;
	cnt[1] --;
	cnt[6] --;
	cnt[8] --;
	cnt[9] --;
	string ans;
	rep(d, 10) rep(i, cnt[d]) ans += char('0' + d);
	int x = 1, y = 0;
	rep(i, ans.size()) {
		y = (y + x * (ans[i]-'0')) % 7;
		x = x * 10 % 7;
	}
//	cerr << "x: " << x << ", y: " << y << endl;
	ans += ok[x][(7 - y) % 7];
	reverse(all(ans));
	puts(ans.c_str());
	return 0;
}