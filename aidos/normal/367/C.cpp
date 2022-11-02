#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
ll get(int g){
	if(g%2 == 1) return 1;
	return g/2;
}
int main () {
	int n, m;
	cin >> n >> m;
	vector < pii > v;
	for(int i = 0; i<m; i++){
		int q, w;
		cin >> q >> w;
		v.pb(mp(w, q));
	}
	sort(v.begin(), v.end());
	for(int i = m-1; i>=0; i--){
		if(i*1ll*(i+1)/2 + get(i+1)<= n){
			ll ans = 0, t = i;
			while(t >= 0){
				t--;
				m--;
				ans += v[m].ff;
			}
			cout << ans <<endl;
			return 0;
		}
	}
    return 0;
}