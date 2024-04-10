#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , ans = -1;
double p;

double C2(int n){
	return n * (n - 1) / 2;
}

double C3(int n){
	return n * (n - 1) * (n - 2) / 6;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> p;
	for(int i = 0 ; i <= n ; i++){
		double P = 1 - (C3(n - i) + C2(n - i) * i / 2) / C3(n);
		if(P >= p){
			ans = i;
			break;
		}
	}
	cout << ans << endl;

    return 0;
}
/*

*/