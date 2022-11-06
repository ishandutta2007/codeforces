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

ll dp[2010][2010];

ll f(int a, int x){
	if(a < 0 || x < 0 || a > x) return 0;
	if(dp[a][x] == -1){
		return dp[a][x] = (f(a+1,x-1) + f(a-1,x-1))%md;
	} else
		return dp[a][x];
}

int main(){
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 1;
	int n,m;
	scanf("%d%d",&n,&m);
	char s[int(1e5)+1];
	scanf(" %s ",s);
	int d = 0, r = 0;
	rep(i,0,m){
		d += s[i]=='('?1:-1;
		r = min(r,d);
	}
	int lf = n-m;
	int a = -r, b = a+d;
	ll ans = 0;
	rep(x,0,lf+1) rep(y,0,x+a+1){
		//cout << x << ' ' << f(a,x)*f(b,lf-x)%md << endl;
		ans += f(a+y,x)*f(b+y,lf-x)%md;
	}
	cout << ans%md << endl;
}