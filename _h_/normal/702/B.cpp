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
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	map<int, ll> cnt;
	ll ans = 0;
	rep(_,0,n){
		int x;
		cin >> x;
		++cnt[x];
	}
	for(ll t = 2; t <= 2e9; t *= 2){
		trav(p, cnt){
			if(2*p.first < t){
				if(cnt.count(t - p.first))
					ans += p.second * cnt[t-p.first];
			} else if(2*p.first == t){
				ans += p.second*(p.second-1)/2;
			} else {
				break;
			}
		}
	}
	cout << ans << endl;
}