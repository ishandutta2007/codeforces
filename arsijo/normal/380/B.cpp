#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 2e5 + 1;
#endif

inline bool in(int l, int x, int r){
	return (l <= x && x <= r);
}

bool check(int l1, int r1, int l2, int r2){
	return (in(l1, l2, r1) || in(l1, r2, r1) || in(l2, l1, r2) || in(l2, r1, r2));
}

int lg[MAX];//log2

inline int getL(int pos){
	return (pos + lg[pos] + 1 - (pos & (pos - 1) ? 0 : 1));
}

inline int getR(int pos){
	return (pos + lg[pos] + 1);
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	vector<pair<ii, int> > vec[n];

	lg[0] = lg[1] = 0;
	for(int i = 2, j = 0, need = 2; i < MAX; i++){
		if(i == need){
			j++;
			need <<= 1;
		}
		lg[i] = j;
	}

	for(int i = 0; i < m; i++){

		int type;
		cin >> type;

		if(type == 1){

			int t, l, r, x;
			cin >> t >> l >> r >> x;
			vec[t - 1].push_back(make_pair(make_pair(l, r), x));

		}else{

			int t, l, r;
			cin >> t >> l;
			r = l;

			set<int> s;

			for(int i = t - 1; i < n; i++){
				for(int j = 0; j < (int) vec[i].size(); j++){
					if(check(l, r, vec[i][j].first.first, vec[i][j].first.second))
						s.insert(vec[i][j].second);
				}
				l = getL(l);
				r = getR(r);
			}

			cout << s.size() << endl;

		}

	}

}