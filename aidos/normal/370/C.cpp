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
int main () {
	set < pii > s, u;
	vector < pii > v;
	int a[1000], n, m;
	for(int i = 0; i<900; i++)
		a[i] = 0;
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		int x;
		cin >> x;
		a[x]++;
	}
	for(int i = 1; i<=m; i++){
		if(a[i] != 0){
			s.insert(mp(a[i], i));
			u.insert(mp(a[i], i));
		}
	}

	while(s.size() > 0 && u.size() > 0){
		set < pii > :: iterator it1 = s.end(), it2 = u.end(), itt1 = s.begin(), itt2=u.begin();
		it1--;
		it2--;
		bool ok1 = 1, ok2 = 1;
		while(itt1 != s.end() && it2 -> sc==itt1->sc) itt1++;
		while(itt2 != u.end() && it1 -> sc==itt2->sc) itt2++;
		if(itt1 == s.end()) ok2 = 0;
		if(itt2 == u.end()) ok1 = 0;
		if(ok1 == 0&& ok2 == 0) break;
		if(ok1){
			if(ok2){
				if((it1->ff) >= (it2->ff)){
					int x = it1->ff, y = it1->sc, z = itt2 -> ff, t = itt2->sc;
					v.pb(mp(y, t));
					x--;
					z--;
					s.erase(it1);
					u.erase(itt2);
					if(x>0) s.insert(mp(x, y));
					if(z > 0) u.insert(mp(z, t));
				}
				else {
					int x = it2->ff, y = it2->sc, z = itt1 -> ff, t = itt1->sc;
					v.pb(mp(t, y));
					x--;
					z--;
					u.erase(it2);
					s.erase(itt1);
					if(x>0) u.insert(mp(x, y));
					if(z > 0) s.insert(mp(z, t));
				}
			}
			else {
					int x = it1->ff, y = it1->sc, z = itt2 -> ff, t = itt2->sc;
					v.pb(mp(y, t));
					x--;
					z--;
					s.erase(it1);
					u.erase(itt2);
					if(x>0) s.insert(mp(x, y));
					if(z > 0) u.insert(mp(z, t));
			}
		}
		else if(ok2){
					int x = it2->ff, y = it2->sc, z = itt1 -> ff, t = itt1->sc;
					v.pb(mp(t, y));
					x--;
					z--;
					u.erase(it2);
					s.erase(itt1);
					if(x>0) u.insert(mp(x, y));
					if(z > 0) s.insert(mp(z, t));
		}
		else break;
	}
	if(s.size() == 1 && u.size() == 1){
		int x = s.begin() -> sc, y = s.begin() -> ff;
		while(y>0){
			v.pb(mp(x, x));
			y--;
		}
	}
	int cnt = 0;
	for(int i =0; i<v.size(); i++){
		if(v[i].ff != v[i].sc) cnt++;
	}
	cout << cnt << endl ;
	for(int i =0; i<v.size(); i++){
		cout<<v[i].ff << " " << v[i].sc << endl;
	}
    return 0;
}