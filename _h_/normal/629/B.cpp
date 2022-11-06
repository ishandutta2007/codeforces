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

int main(){
	int n;
	cin >> n;
	vi m(367),f(367);
	rep(_,0,n){
		char c;
		int a,b;
		cin >> c >> a >> b;
		if(c=='M') rep(i,a,b+1) m[i] ++;
		else rep(i,a,b+1) f[i] ++;
	}
	int ans = 0;
	rep(i,0,367) ans = max(ans, 2*min(m[i],f[i]));
	cout << ans << endl;
}