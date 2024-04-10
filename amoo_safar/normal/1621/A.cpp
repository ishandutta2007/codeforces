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

int Main(){
	int n, k;
	cin >> n >> k;
	int lm = ( n + 1) / 2;
	if(lm < k) return cout << "-1\n", 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ".R"[(i == j) && (i % 2 == 0) && (i <= 2 * (k - 1))];
		}
		cout << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}