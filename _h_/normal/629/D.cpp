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
const double pi = acos(-1);

int main(){
	int n;
	scanf("%d",&n);
	map<ll, ll> dp;
	dp[0] = 0;
	ll res = 0;
	while(n--){
		ll r,h;
		scanf("%d%d",&r,&h);
		ll vol = r*r*h;
		auto it = dp.lower_bound(vol);
		--it;
		dp[vol] = it->second + vol;
		res = max(res, dp[vol]);
		while(5){
			it = dp.upper_bound(vol);
			if(it != dp.end() && it->second < dp[vol])
				dp.erase(it);
			else
				break;
		}
	}
	cout.precision(15);
	cout << (double)res*pi << endl;
}