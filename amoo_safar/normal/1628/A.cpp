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

const int Mod = 1000000007LL;
const int N = 2e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

vector<int> R[N];

int a[N];
int Main(){
	int n;
	cin >> n;
	vector<int> A;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = n - 1; i >= 0; i--) R[a[i]].pb(i);

	int po = 0;
	for(; po < n; ){
		if(R[0].empty()){
			R[a[po]].pop_back();
			po ++;
			A.pb(0);
			continue;
		}
		int nx = po;
		int mx = 0;
		for(; !R[mx].empty(); mx++) nx = max(nx, R[mx].back());

		// while(!R[mx].empty()){
			// int nx = R[mx].back();
		for(int i = po; i <= nx; i++) R[a[i]].pop_back();
		po = nx + 1;
		A.pb(mx);
	}

	cout << A.size() << '\n';
	for(auto x : A) cout << x << ' ';
	cout << '\n';

	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc --) Main();
	return 0;
}