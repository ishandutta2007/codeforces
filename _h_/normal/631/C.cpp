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

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vi a(n);
	rep(i,0,n) scanf("%d",&a[i]);
	vi t(m), r(m);
	rep(i,0,m) scanf("%d %d",&t[i],&r[i]);
	vi ixs;
	int rek = 0;
	rrep(i,0,m){
		if(r[i] > rek){
			rek = r[i];
			ixs.pb(i);
		}
	}
	sort(a.begin(),a.begin()+rek);
	deque<int> d;
	rep(i,0,rek) d.pb(a[i]);
	int pos = rek-1;
	rrep(s,0,ixs.size()){
		int ix = ixs[s];
		int nx = s==0 ? 0 : r[ixs[s-1]];
		if(t[ix] == 1){
			rep(x,nx,r[ix]){
				a[pos--] = d.back();
				d.pop_back();
			}
		} else {
			rep(x,nx,r[ix]){
				a[pos--] = d.front();
				d.pop_front();
			}
		}
	}
	rep(i,0,n) printf("%d ",a[i]);
	puts("");
}