#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

#define mp make_pair
#define pb push_back




int main() {
	ll x, y, p, q;
	int t;
	cin >> t;
	while(t--){
		cin >> x >> y >> p >> q;
		if(p==q || p==0){
			if((p==q && x==y) || (p==0&&x==0)) cout << 0 << endl;
			else cout << -1 << endl;
			continue;
		}
		ll lo = 0;
		ll hi = 1e9;
		while(hi-lo >1){
			ll m  = (lo+hi)/2;
			if(m*q>=y && m*p>=x && m*p-x<=m*q-y){
				hi = m;
			}
			else{
				lo = m;
			}
		}
		cout << (hi*q-y) << endl;
	} 
}