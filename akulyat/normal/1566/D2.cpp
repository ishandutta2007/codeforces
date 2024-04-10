#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m, k;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> m;
	k = n * m;
	v.resize(k);
	for (auto &i : v)
		cin >> i;

	vector<int> nums(k);
	iota(nums.begin(), nums.end(), 0);

	sort(nums.begin(), nums.end(), [](int a, int b){
		if (v[a] == v[b])
			return a < b;
		return v[a] < v[b];
	});

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int h = 0; h < j; h++) {
				int pl1 = i * m + j;
				int pl2 = i * m + h;
				int p1 = nums[pl1];
				int p2 = nums[pl2];
				if (v[p1] != v[p2] && p1 > p2)
					ans++;
			}
		}
	}	
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}