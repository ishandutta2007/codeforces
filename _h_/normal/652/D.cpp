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

vi t;

void upd(int a, int d){
	for(++a; a < t.size(); a += a&-a) t[a] += d;
}

int que(int a){
	int res = 0;
	for(; a; a -= a&-a) res += t[a];
	return res;
}

int main(){
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vi ls(n), rs(n);
	vi nums(2*n);
	rep(i,0,n){
		cin >> ls[i] >> rs[i];
		nums[2*i] = ls[i];
		nums[2*i+1] = rs[i];
	}
	sort(allof(nums));
	map<int, int> ren;
	rep(i,0,2*n) ren[nums[i]] = i;
	rep(i,0,n){
		ls[i] = ren[ls[i]];
		rs[i] = ren[rs[i]];
	}
	t.resize(2*n);
	rep(i,0,n) upd(rs[i],1);
	vi ix(n);
	rep(i,0,n) ix[i] = i;
	sort(allof(ix), [&](int a, int b){
		return ls[a] < ls[b];
	});
	vi ans(n);
	for(int i : ix){
		upd(rs[i],-1);
		ans[i] = que(rs[i]);
	}
	rep(i,0,n) cout << ans[i] << endl;
}