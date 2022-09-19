
// Dennis - Toney
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

const ll Mod = 1000000007LL;
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int A[N];

int Main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	int mn = *min_element(A, A + n);
	int mx = *max_element(A, A + n);
	cout << min_element(A + 1, A + 1 + n) - A << ' ' << max_element(A + 1, A  + 1 + n) - A << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}