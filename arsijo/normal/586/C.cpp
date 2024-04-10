#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-8;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int v[n], d[n], p[n];
	for(int i = 0; i < n; i++)
	cin >> v[i] >> d[i] >> p[i];

	int next = 0;
	vector<int> ans;

	int s[n + 1];
	while(next < n) {
		ans.push_back(next + 1);
		dbg << next + 1 << " is ok" << endl;
		int t = -1;
		int e = v[next];
		ms(s, 0);
		for(int i = next + 1; i < n; i++) {
			if(p[i] >= 0 && e) {
				p[i] -= e--;
				if(p[i] < 0){
					s[i] += d[i];
				}
			}
		}
		e = 0;
		for(int i = next + 1; i < n; i++){
			if(p[i] >= 0){
				p[i] -= e;
				if(p[i] < 0){
					e += d[i];
				}else if(t == -1){
					t = i;
				}
			}else{
				e += s[i];
			}
		}
		if(t == -1)
		break;
		next = t;
	}

	cout << ans.size() << endl;
	for(int i = 0; i < (int) ans.size(); i++)
	cout << ans[i] << " ";

}