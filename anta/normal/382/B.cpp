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

int w, x;
ll vis[1001], visa[1001];

ll getacount(ll k, int b) {
	mset(vis, -1);
	ll acnt = 0;
	bool f = false;
	for(ll i = 0; i < k; i ++) {
		if(!f && vis[b] != -1) {
			ll y = i - vis[b];
			ll z = acnt - visa[b];
			ll cy = (k - i) / y;
			i += cy * y;
			acnt += cy * z;
			f = true;
			i --;
			continue;
		}
		if(!f) {
			vis[b] = i;
			visa[b] = acnt;
		}
		if(b < x) {
			acnt ++;
			b = w - (x - b);
		}else {
			b = b - x;
		}
	}
	return acnt;
}

int main() {
	int a, b, c;
	scanf("%d%d%d%d%d", &a, &b, &w, &x, &c);
	ll l = 0, u = INFL;
	while(u-l > 0) {
		ll mid = (l + u) / 2;
//		cerr << mid << endl;
		if(c - mid <= a - getacount(mid, b))
			u = mid;
		else
			l = mid+1;
	}
	cout << u << endl;

	return 0;
}