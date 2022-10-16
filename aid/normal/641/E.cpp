#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <map>
#include <set>
#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forab(i,a,b) for(int i=(int)a;i<(int)b;i++) //WARNING!! long long
#define mp make_pair
#define pb push_back
#define all(a,n) a,a+n
#define dprintf if(DEBUG)printf
#define dputs if(DEBUG)puts
#define dassert if(DEBUG)assert
#define fi first
#define se second
#define j0 jqwerty
#define j1 jasdf
#define i0 iqwerty
#define i1 iasdf
#define sq(x) (x)*(x)

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 2e5;
int DEBUG=1;
map<int, int> fr;
vector<int> sr;
int s[maxn];

vector<vector<int> > tm;
const int sh = (1 << 19);
int rmq[2 * sh + 5];
void upd(int v, int l, int r, int p, int vl){
	if(p < l || r < p)return;
	if(p == l && r == p){
		rmq[v] = vl;
		return;
	}
	int m = (l + r)/2;
	upd(2 * v, l, m, p, vl);
	upd(2 * v + 1, m + 1, r, p, vl);
	rmq[v] = rmq[2 * v] + rmq[2 * v + 1];
}
int take(int v, int l, int r, int a, int b){
	
	if(a <= l && r <= b){
		return rmq[v];
	}
	if(b < l || r < a){
		return 0;
	}
	int m = (l + r)/ 2;
	return take(2 * v, l, m, a, b) + take(2 * v + 1, m + 1, r, a, b);

}
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n), t(n), x(n);
	forn(i, n)
		scanf("%d %d %d", &a[i], &t[i], &x[i]);
	forn(i, n)
		sr.pb(x[i]);
	sort(sr.begin(), sr.end());
	sr.resize(unique(sr.begin(), sr.end()) - sr.begin());
	forn(i, sr.size()){
		fr[sr[i]] = i;
	}
	tm.resize(fr.size());
	forn(i, n){
		tm[fr[x[i]]].pb(t[i]);
	}
	forn(i, fr.size()){
		sort(tm[i].begin(), tm[i].end());
	}
	for(int i = 1; i < fr.size(); i++){
	    s[i] = s[i-1] + tm[i-1].size();
	}
	forn(i, n){
		int j = fr[x[i]];
		int p = lower_bound(tm[j].begin(), tm[j].end(), t[i]) - tm[j].begin();
		if(a[i] == 1){
			upd(1, 0, sh - 1, p + s[j], +1);
		}
		if(a[i] == 2){
			upd(1, 0, sh - 1, p + s[j], -1);
		}
		if(a[i] == 3){
			printf("%d\n", take(1, 0, sh - 1, s[j], s[j] + p));
		}
	}
	return 0;
}