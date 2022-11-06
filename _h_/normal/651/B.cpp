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
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	multiset<int> as;
	rep(i,0,n){
		int a;
		cin >> a;
		as.insert(a);
	}
	int ans = n;
	while(!as.empty()){
		ans--;
		auto it = as.begin();
		while(it != as.end()){
			auto nx = as.upper_bound(*it);
			as.erase(it);
			it = nx;
		}
	}
	cout << ans << endl;
}