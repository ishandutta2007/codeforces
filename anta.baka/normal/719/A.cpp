#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


int main() {
	ios_base::sync_with_stdio(0);
	int n, a, b;
	cin >> n >> b;
	for(int i = 1; i < n; i++) {
		a = b;
		cin >> b;
	}
	if(b == 15) {
		cout << "DOWN";
		return 0;
	}
	if(b == 0) {
		cout << "UP";
		return 0;
	}
	if(n == 1) {
		cout << -1;
		return 0;
	}
	if(a < b) {
		cout << "UP";
		return 0;
	}
	if(a > b) {
		cout << "DOWN";
		return 0;
	}
}