#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define forit(it, v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++)

typedef pair <int, int > pii;

typedef pair <long long, long long > pll;
typedef vector <int> vi;
typedef long long ll;

ll pw1[600005];
string ss[300100];
vector < pair < pii, string > > v;
ll mod1 = 100000007;
ll mod2 = 1100009;
int main(){
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

	set < string > S;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string t;
		cin >> t;
		v.pb(mp(mp(t.size(), 0), t));
	}
	for(int i = 0; i < m; i++){
		cin >> ss[i];
		v.pb(mp(mp(ss[i].size(), 1), ss[i]));
	}
	sort(v.begin(), v.end());

	v.resize(unique(v.begin(), v.end()) - v.begin());

	int x = v.size();
	for(int i = 0; i < x; ){
		int j = i;
		while(i < x && v[i].f.f == v[j].f.f) i++;
		int k= j;
		while(k < i && v[k].f.s == 0) k++;
		set < pll > hs;
		while(j < k){
			ll tt1 = 0, tt2 = 0;
			string &y = v[j].s;
			for(int t = y.size()-1; t >= 0; t--){
				tt1 = (tt1 * 31ll + (y[t] - 'a' + 1)) % mod1;
				tt2 = (tt2 * 29ll + (y[t] - 'a' + 1)) % mod2;
			}
			hs.insert(mp(tt1, tt2));
			j++;
		}
		while(j < i){
			ll tt1 = 0, tt2 = 0;
			string &y = v[j].s;
			for(int t = y.size()-1; t >= 0; t--){
				tt1 = (tt1 * 31ll + (y[t] - 'a' + 1)) % mod1;
				tt2 = (tt2 * 29ll + (y[t] - 'a' + 1)) % mod2;
			}
			bool ok=false;
			ll z1 = 1, z2=1;
			for(int t = 0; t < y.size() && !ok; t++){
				if(y[t] == 'a'){
					if(hs.count(mp((tt1 + z1) % mod1, (tt2+z2) % mod2)) || hs.count(mp((tt1 + z1 + z1) % mod1, (tt2+z2+z2) % mod2))) ok = true;
				}
				if(y[t] == 'b'){
				    if(hs.count(mp((tt1 + z1) % mod1, (tt2 + z2) % mod2)) || hs.count(mp((tt1 - z1 + mod1) % mod1, (tt2-z2+mod2) % mod2))) ok = true;
				}
				if(y[t] == 'c'){
					ll x1 = (-z1 + mod1) % mod1;
					ll x2 = (-z2 + mod2) % mod2;
				    if(hs.count(mp((tt1 +x1+x1) % mod1, (tt2+x2+x2) % mod2)) || hs.count(mp((tt1 +x1) % mod1, (tt2+x2) % mod2))) ok = true;
				}
				z1 = z1 * 31ll % mod1;
				z2=z2 * 29ll % mod2;
			}
			j++;
			//cout <<"1 " << y << endl;
			if(ok) S.insert(y);
		}
	}
	for(set < string > :: iterator it = S.begin(); it != S.end(); it++){
		//cout << *it << endl;

	}	
	for(int i = 0; i < m; i++){
		if(S.count(ss[i])) cout << "YES\n";
		else cout << "NO\n";
	}








	#ifdef LOCAL
	cerr << 1.0 * clock()/CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}