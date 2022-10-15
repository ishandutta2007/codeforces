#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-10;
#define null NULL
#define y1 ybutnot1
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 7e5;
int ar[MAX][10], sz = 1;

inline void make(string a, string &b, string &c) {
	b = "";
	c = "";
	for (int i = 7; i < (int) a.size(); i++) {
		if (a[i] == '/') {
			b = a.substr(7, i - 7);
			c = a.substr(i, (int) a.size() - i);
			return;
		}
	}
	b = a.substr(7, (int) a.size() - 7);
}

struct lze_map {
	map<string, int> m;
	inline int get(string s) {
		if (m.find(s) == m.end()) {
			int ind = (int) m.size();
			m[s] = ind;
		}
		return m[s];
	}
};

vector<int> w;
int q;

inline void add(int &pos, int n) {
	for (int i = 0; i < 6; i++) {
		q = n % 10;
		if (ar[pos][q] == 0)
			ar[pos][q] = sz++;
		pos = ar[pos][q];
		n /= 10;
	}
}

void rand_test() {
	ofstream cout("input.txt");
	int n = 1e5;
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << "http://";
		for (int j = 0; j < 3; j++)
			cout << char('a');
		cout << "/";
		for (int j = 0; j < 1; j++)
			cout << char('a');
		cout << endl;
	}
	cout.close();
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	ms(ar);

	int n;
	cin >> n;
	string s, s1, s2;
	lze_map m1, m2;
	vector<ii> vec;
	for(int i = 0; i < n; i++) {
		cin >> s;
		make(s, s1, s2);
		vec.push_back(make_pair(m1.get(s1), m2.get(s2)));

	}

	sort(vec.begin(), vec.end());

	vector<int> v;

	vector<ii> ans;

	for(int i = 0; i < (int) vec.size(); i++) {
		v.clear();
		v.push_back(vec[i].second);
		while(i + 1 < (int) vec.size() && vec[i].first == vec[i + 1].first) {
			i++;
			if(vec[i].second != v.back())
			v.push_back(vec[i].second);
		}
		int pos = 0;
		for(int j = 0; j < (int) v.size(); j++)
		add(pos, v[j]);
		ans.push_back(make_pair(pos, vec[i].first));
	}

	sort(ans.begin(), ans.end());

	string r[m1.m.size()];
	for(map<string, int>::iterator it = m1.m.begin(); it != m1.m.end(); it++)
	r[it->second] = it->first;
	v.clear();

	int an = 0;

	for(int i = 0; i < (int) ans.size(); i++) {
		v.clear();
		v.push_back(ans[i].second);
		while(i + 1 < (int) ans.size() && ans[i].first == ans[i + 1].first) {
			i++;
			v.push_back(ans[i].second);
		}
		if((int) v.size() > 1) {
			an++;
		}
	}

	cout << an << endl;

	for(int i = 0; i < (int) ans.size(); i++) {
		v.clear();
		v.push_back(ans[i].second);
		while(i + 1 < (int) ans.size() && ans[i].first == ans[i + 1].first) {
			i++;
			v.push_back(ans[i].second);
		}
		if((int) v.size() > 1) {
			an++;
			for(int i = 0; i < (int) v.size(); i++)
			cout << "http://" << r[v[i]] << " ";
			cout << endl;
		}
	}

}