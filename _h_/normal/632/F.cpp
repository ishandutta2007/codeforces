#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;
const ll inf = 1LL<<60;
const ll md = 1e9+7;
const ld eps = 1e-14;
const ld pi = acos(-1);

void fail(){
	puts("NOT MAGIC");
	exit(0);
}

vector<vi> a;

int d(const pii &x){
	return a[x.first][x.second];
}

bool cmp(const pii &x, const pii &y){
	return d(x) > d(y);
}

int main(){
	int n;
	scanf("%d",&n);
	a.resize(n,vi(n));
	rep(i,0,n) rep(j,0,n) scanf("%d",&a[i][j]);
	rep(i,0,n) if(a[i][i] != 0) fail();
	rep(i,0,n) rep(j,i+1,n) if(a[i][j] != a[j][i]) fail();
	vector<bitset<2500> > bs(n,0);
	vector<pii> vp;
	rep(i,0,n) rep(j,i,n) vp.pb(pii(i,j));
	sort(allof(vp),cmp);
	for(int i = 0; i < vp.size();){
		int j = i+1;
		while(j < vp.size() && d(vp[j]) == d(vp[i])) ++j;
		rep(k,i,j){
			int x = vp[k].first, y = vp[k].second;
			bs[x][y] = bs[y][x] = 1;
		}
		rep(k,i,j)
			if((bs[vp[k].first] | bs[vp[k].second]).count() < n)
				fail();
		i = j;
	}
	puts("MAGIC");
}