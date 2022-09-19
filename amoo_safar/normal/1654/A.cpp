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
const int N = 3e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

int A[N];

int Main(){
	vector<ll> V;
	int n;
	cin >> n;
	ll x;
	for(int i = 0; i < n; i++){
		cin >> x;
		V.pb(x);
	}
	sort(all(V));
	reverse(all(V));
	cout << V[0] + V[1] << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}