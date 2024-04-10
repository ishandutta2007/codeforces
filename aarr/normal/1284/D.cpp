#include <bits/stdc++.h>
using namespace std;


const int N = 100 * 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 7;
int n;

int s1[N], e1[N], s2[N], e2[N];
pair <int, int> a[N];
pair <int, int> b[N];
int c[N];
multiset <pair <int, int> > st;
multiset <int> st2;
multiset <int> st3;


int main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s1[i] >> e1[i] >> s2[i] >> e2[i];
		a[i] = {s1[i], i};
		b[i] = {e1[i], i};
	}
	sort(a, a + n);
	sort(b, b + n);
	st.insert({inf, n});
	st2.insert(inf);
	st3.insert(inf);
	bool ans = true;
	for (int i = 0; i < n; i++) {
		pair <int, int> p = *st.begin();
	//	cout << "49 " << i << endl;
		while (p.first < a[i].first) {
	//		cout << "23 " << p.first << " " << p.second << endl;
			st2.erase(st2.find(-s2[p.second]));
		//	cout << 36 << endl;
			st3.erase(st3.find(e2[p.second]));
			st.erase(st.begin());
		//	cout << 35 << endl;
			p = *st.begin();
		//	cout << 34 << endl;
		}
		int x = -*st2.begin(), y = *st3.begin();
		int l = s2[a[i].second], r = e2[a[i].second];
	//	cout << "73 " << l << " " << r << " " << x << " " << y << endl;
		if (r < x || y < l) {
			ans = false;
		}
		st.insert({e1[a[i].second], a[i].second});
		st2.insert(-s2[a[i].second]);
		st3.insert(e2[a[i].second]);
	}
	st.clear();
	st2.clear();
	st3.clear();
	for (int i = 0; i < n; i++) {
		a[i] = {s2[i], i};
		b[i] = {e2[i], i};
	}
	sort(a, a + n);
	sort(b, b + n);
	st.insert({inf, n});
	st2.insert(inf);
	st3.insert(inf);
	for (int i = 0; i < n; i++) {
		pair <int, int> p = *st.begin();
	//	cout << "49 " << i << endl;
		while (p.first < a[i].first) {
	//		cout << "23 " << p.first << " " << p.second << endl;
			st2.erase(st2.find(-s1[p.second]));
		//	cout << 36 << endl;
			st3.erase(st3.find(e1[p.second]));
			st.erase(st.begin());
		//	cout << 35 << endl;
			p = *st.begin();
		//	cout << 34 << endl;
		}
		int x = -*st2.begin(), y = *st3.begin();
		int l = s1[a[i].second], r = e1[a[i].second];
	//	cout << "73 " << l << " " << r << " " << x << " " << y << endl;
		if (r < x || y < l) {
			ans = false;
		}
		st.insert({e2[a[i].second], a[i].second});
		st2.insert(-s1[a[i].second]);
		st3.insert(e1[a[i].second]);
	}
	if (ans) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}