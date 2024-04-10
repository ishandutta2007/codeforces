#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define y1 asd
#define left asdleft
#define right asdright
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-7;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

void rand_test(){
	ofstream cout("input.txt");
	int n = rand() % 10 + 2;
	int m = rand() % 10 + n - 1;
	cout << n << " " << m << endl;
	for(int i = 1; i < n; i++){
		cout << rand() % 10 + 1  << " 1" << endl;
	}
	for(int i = n - 1; i < m; i++){
		cout << rand() % 10 + 1 << " 0" << endl;
	}
}

int main() {
	sync;
	srand(time(NULL));

#ifdef LOCAL
	//rand_test();
	input;
	//output;
#else

#endif

	ll n, m;
	cin >> n >> m;

	vector<iii> vec;
	vec.reserve(m);
	for(int i = 0; i < m; i++){
		ll a, b;
		cin >> a >> b;
		vec.push_back(make_pair(make_pair(a, 1 - b), make_pair(i, i)));
	}
	sort(vec.begin(), vec.end());

	ll now = 1, can_be = 0, ind = 0;
	ll l = 3, r = 1;
	vector<ii> ans(m);
	for(int i = 0; i < (int) vec.size(); i++){
		if(vec[i].first.second){
			if(ind == can_be){
				cout << -1;
				return 0;
			}
			ans[vec[i].second.first] = make_pair(l, r);
			r++;
			if(r == l - 1){
				l++;
				r = 1;
			}
			ind++;
		}else{
			can_be += now;
			ans[vec[i].second.first] = make_pair(now, now + 1);
			ind++;
			now++;
		}
	}

	for(int i = 0; i < m; i++)
		cout << ans[i].first << " " << ans[i].second << endl;

}