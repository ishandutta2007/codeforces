// Son
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int a[N], b[N];
int Main(){

	int n;
	cin >> n;
	map<int, int> mp;
	int mx = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]] ++;
		mx = max(mx, mp[a[i]]);
	}
	vector<int> I(n);
	iota(all(I), 0);
	sort(all(I), [&](int i, int j){
		return a[i] < a[j];
	});
	for(int i = 0; i < n; i++){
		int nx = I[(i + mx) % n];
		b[nx] = a[I[i]];
	}
	for(int i = 0; i < n; i++) cout << b[i] << ' ';
	cout << '\n';
	return 0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}