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
vector < pii > v[5100];
vector < int > p;
vector < bool > zz(45000, 0);
ll n, m, x, a[5100];
vector < pii > gcd[5100];
set < int > s;
void get(ll y, int c){
	int k = 0;
	while(p[k] * p[k] <=y){
		if(y%p[k] == 0){
			int aa = 0;
			while(y % p[k] == 0){
				aa++;
				y/=p[k];
			}
			v[c].pb(mp(p[k], aa));
		}
		k++;
	}
	if(y > 1) v[c].pb(mp(y, 1));
}
void getgcd(int y){
	if(y == 0) gcd[0] = v[0];
	else {
		for(int i = 0; i < gcd[y-1].size(); i++){
			int k = 0;
			for(int j = 0; j < v[y].size(); j++){
				if(v[y][j].ff == gcd[y-1][i].ff){
					k = min(v[y][j].sc, gcd[y-1][i].sc);
				}
				else if(v[y][j].ff > gcd[y-1][i].ff) break;
			}
			if(k != 0){
				gcd[y].pb(mp(gcd[y-1][i].ff, k));
			}
		}
	}
}
ll summ(int y){
	ll sum=0, k = 0;
	while(p[k] * p[k] <= y){
		if(y%p[k] == 0){
			int aa;
			if(s.find(p[k]) == s.end()) aa = 1;
			else aa = -1;
			while(y % p[k] == 0) sum+=aa, y/=p[k];
		}
		k++;
	}
	if(y > 1){
	    if(s.find(y) == s.end()) return sum + 1;
		else return sum-1;	
	}
	return sum;
}
int gg[5100];
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    for(int i = 2; i< 40000; i++){
    	if(!zz[i]){
    		for(int j = i; j < 40000; j+=i){
    			zz[j] = 1;
    		}
    		p.pb(i);
    	}
    }
    cin >> n >> m;                                                                                                        
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	get(a[i], i);              
    	getgcd(i);
    	if(i) gg[i] = __gcd(gg[i-1], (int) a[i]);
    	else gg[i] = a[i];
    }
    for(int j = 0; j < m; j++){
    	cin >> x;
    	s.insert(x);
    }
    ll maxn = 0;
	/*for(int i = 0; i < n; i++){
		ll hh = 0;
		for(int j = 0; j < gcd[i].size(); j++){
			if(s.find(gcd[i][j].ff)==s.end()) hh += gcd[i][j].sc;
			else hh -= gcd[i][j].sc;
		}
		hh = hh * 1ll * (i + 1);
		if(maxn < sum  -  hh) maxn = sum - hh;
	} */
	for(int i = n-1; i >= 0; i--){
		if(gg[i]  != 1 && summ(gg[i]) < 0)
			for(int j = 0; j<=i; j++){
				a[j]/=gg[i];
				gg[j]/=gg[i];
			}
	}
	for(int i = 0; i < n; i++)
		maxn = maxn + summ(a[i]);
	cout << maxn;
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}