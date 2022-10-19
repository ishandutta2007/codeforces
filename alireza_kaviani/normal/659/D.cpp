#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , S , pos , neg;
pll P[MAXN];

ll cross(pll x , pll y){
	return x.X * y.Y - x.Y * y.X;
}

pll To(pll x , pll y){
	return {y.X - x.X, y.Y - x.Y};
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i <= n ; i++){
		cin >> P[i].X >> P[i].Y;
	}
	P[n + 1] = P[1];
	for(int i = 1 ; i <= n ; i++){
		S += cross(P[i - 1] , P[i]);
		ll val = cross(P[i - 1], P[i]) + cross(P[i], P[i + 1]) + cross(P[i + 1], P[i - 1]);
		if(val > 0){
			pos++;
		}
		if(val < 0){
			neg++;
		}
	}
	if(S < 0){
		cout << pos << endl;
	}
	else{
		cout << neg << endl; 
	}

    return 0;
}
/*

*/