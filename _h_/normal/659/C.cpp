#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
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

int main(){
	cin.sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	vi have(n);
	rep(i,0,n) cin >> have[i];
	sort(allof(have));
	have.pb(-1);
	vi ans;
	int ix = 0;
	for(int i = 1; m >= i; ++i){
		while(have[ix] == i){
			++ix;
			++i;
		}
		if(m >= i){
			ans.pb(i);
			m -= i;
		}
	}
	cout << ans.size() << endl;
	for(int a : ans) cout << a << ' ' ;
		cout << endl;
}