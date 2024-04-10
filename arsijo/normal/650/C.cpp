#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-11;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#define endl "\n"
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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

template<typename t>
void del(vector<t> &vec, int ind){
	swap(vec[ind], vec[vec.size() - 1]);
	vec.pop_back();
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

	int n, m;
	cin >> n >> m;

	int **ar = new int*[n];
	for(int i = 0; i < n; i++) {
		ar[i] = new int[m];
		for(int j = 0; j < m; j++) {
			cin >> ar[i][j];
		}
	}

	set<pair<int, ii> > s;

	int max_n[n], max_m[m];
	ms(max_n);
	ms(max_m);

	unordered_map<int, vector<ii> > m1[n], m2[m];

	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++) {
		s.insert(make_pair(ar[i][j], make_pair(i, j)));
		m1[i][ar[i][j]].push_back(make_pair(i, j));
		m2[j][ar[i][j]].push_back(make_pair(i, j));
	}

	int ans[n][m];
	int nn[n], mm[m];
	ms(nn);
	ms(mm);

	bool used[n][m];
	ms(used);
	int q = 0;

	vector<ii> v, ttt;
	v.reserve(n * m);
	vector<ii> &ve = ttt;
	ii point;
	for(set<pair<int, ii> >::iterator it = s.begin(); it != s.end(); it++) {
		point = it->second;
		if(used[point.first][point.second])
		continue;
		int t = 1;
		q++;
		v.clear();
		v.push_back(it->second);
		used[point.first][point.second] = true;
		for(int i = 0; i < (int) v.size(); i++) {
			t = max(t, max(max_n[v[i].first], max_m[v[i].second]) + 1);
			if(nn[v[i].first] != q) {
				nn[v[i].first] = q;
				ve = m1[v[i].first][it->first];
				for(int j = 0; j < (int) ve.size(); j++) {
					if(!used[ve[j].first][ve[j].second]) {
						used[ve[j].first][ve[j].second] = true;
						v.push_back(make_pair(ve[j].first, ve[j].second));
						del(ve, j);
						j--;
					}
				}
			}
			if(mm[v[i].second] != q) {
				mm[v[i].second] = q;
				ve = m2[v[i].second][it->first];
				for(int j = 0; j < (int) ve.size(); j++) {
					if(!used[ve[j].first][ve[j].second]) {
						used[ve[j].first][ve[j].second] = true;
						v.push_back(make_pair(ve[j].first, ve[j].second));
						del(ve, j);
						j--;
					}
				}
			}
		}
		for(int i = 0; i < (int) v.size(); i++) {
			max_n[v[i].first] = max(max_n[v[i].first], t);
			max_m[v[i].second] = max(max_m[v[i].second], t);
			ans[v[i].first][v[i].second] = t;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

}