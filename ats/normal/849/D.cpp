#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
struct T {
	int g;
	int p;
	int t;
	int ind;
	bool operator<(const T& right) const {
		if (g > right.g) {
			return true;
		}
		else if(g==right.g){
			if (g == 2) {
				return p > right.p;
			}
			else {
				return p < right.p;
			}
		}
		return false;
	}
};
signed main() {
	ios_base::sync_with_stdio(false);
	int n, w, h;
	vector<T> a;
	int cnt = 0;
	cin >> n >> w >> h;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].g >> a[i].p >> a[i].t;
		a[i].ind = i;
		if (a[i].g == 2) {
			cnt++;
		}
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		//cerr << a[i].g << " " << a[i].p << endl;
	}
	vector<int> res;
	vector<int> tmp;
	res.resize(n);
	tmp.resize(n);
	map<int, vector<int> > mp;
	vector<int> l;
	for (int i = 0; i < n; i++) {
		mp[a[i].p - a[i].t].push_back(i);
	}
	for (map<int, vector<int> >::iterator m = mp.begin(); m != mp.end(); ++m) {
		int k = 0;

		l = mp[m->first];
		
		for (int i = 0; i < l.size(); i++) {
		//	cerr << l[i] << " ";
		}

		//cerr << endl;
		
		for (int i = 0; i < l.size(); i++) {
			if (l[i] >= cnt) {
				res[l[k]] = l[i];
				k++;
			}
		}
		for (int i = 0; i < l.size(); i++) {
			if (k >= (int)l.size()) {
				break;
			}
			res[l[k]] = l[i];
			k++;
			
		
		}
	}
	for (int i = 0; i < n; i++) {
		tmp[a[i].ind] = res[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[tmp[i]].g == 1) {
			cout << a[tmp[i]].p << " " << h << endl;
		}
		else {
			cout << w << " " << a[tmp[i]].p << endl;
		}
	}
	return 0;
}