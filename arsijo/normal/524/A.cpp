/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld double
#define MAX 500
#define si short int

struct str {
	int name;
	set<int> s;
	str(int a) {
		name = a;
	}
	void add(int a) {
		s.insert(a);
	}
};

bool operator<(str a, str b) {
	return a.name < b.name;
}

bool operator==(str a, str b) {
	return a.name == b.name;
}

vector<str> v;

int find(int a) {
	for (int i = 0; i < v.size(); i++)
		if (v[i].name == a)
			return i;
	return v.size();
}

bool find(int a, int b){
	int f = find(a);
	return v[f].s.find(b) != v[f].s.end();
}

int main() {

	int n, k;
	cin >> n >> k;

	while (n--) {
		int a, b;
		cin >> a >> b;
		int f = find(a);
		if (f == v.size()) {
			str st = str(a);
			st.s.insert(b);
			v.push_back(st);
		} else {
			v[f].add(b);
		}
		f = find(b);
		if (f == v.size()) {
			str st = str(b);
			st.s.insert(a);
			v.push_back(st);
		} else {
			v[f].add(a);
		}
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++){
		cout << v[i].name << ": ";
		vector<int> ans;
		for(int j = 0; j < v.size(); j++){
			if(i != j && v[i].s.find(v[j].name) == v[i].s.end()){
				int a = v[i].s.size(), b = 0;
				int need = a * k / 100 + (a * k % 100 != 0);
				for(int z = 0; z < v.size(); z++){
					if(z != i && z != j && v[z].s.find(v[i].name) != v[z].s.end() && v[z].s.find(v[j].name) != v[z].s.end()){
						b++;
					}
				}
				//cout << i << " " << j << " " << b << " " << need << " " << a << endl;
				if(b >= need)
					ans.push_back(v[j].name);
			}
		}
		cout << ans.size() << " ";
		for(int j = 0; j < ans.size(); j++)
			cout << ans[j] << " ";
		cout << endl;
	}

}