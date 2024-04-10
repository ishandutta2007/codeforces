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

	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	
	int pos = 0;
	int a[m], b[m];
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		b[i]--;
	}
	for(int i = 0; i < m; i++)
		pos = max(pos, b[i]);
	
	vector<iii> vec;
	for(int i = 0; i < m; i++){
		vec.push_back(make_pair(make_pair(b[i], i), make_pair(a[i], 0)));
	}
	sort(vec.rbegin(), vec.rend());
	
	multiset<int> s;
	for(int i = 0; i <= pos; i++)
		s.insert(ar[i]);
	
	int t = 0;
	int q = 0;
	int last = -1;
	for(int j = pos; j >= 0; j--){
		while(t < (int) vec.size() && vec[t].first.first == j){
			if(vec[t].first.second > last){
				last = vec[t].first.second;
				q = vec[t].second.first;
			}
			t++;
		}
		int val = (q == 1 ? *s.rbegin() : *s.begin());
		ar[j] = val;
		s.erase(s.find(val));
	}
	
	for(int i = 0; i < n; i++)
		cout << ar[i] << " ";
	
}