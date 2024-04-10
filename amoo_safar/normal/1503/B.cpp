// Black lives matter !
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

const ll Mod = 998244353;
const int N = 1e5 + 10;
const int Inf = 2000000100;
const ll Log = 30;

vector<pll> A, B;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if((i+j) % 2 == 0) A.pb({i, j});
			else B.pb({i, j});
		}
	}
	int c;
	for(int t = 0; t < n*n; t++){
		cin >> c;
		int my = 3;
		if(!A.empty() && c != 2) my = 2;
		if(!B.empty() && c != 1) my = 1;
		if(my == 1){
			cout << my << ' ' << B.back().F << ' ' << B.back().S << endl;
			B.pop_back();
		}
		if(my == 2){
			cout << my << ' ' << A.back().F << ' ' << A.back().S << endl;
			A.pop_back();
		}
		if(my == 3){
			if(A.empty()){
				cout << my << ' ' << B.back().F << ' ' << B.back().S << endl;
				B.pop_back();		
			} else {
				cout << my << ' ' << A.back().F << ' ' << A.back().S << endl;
				A.pop_back();
			}
		}
	}
	return 0;
}
/*
5 1
1 2
2 3
3 4
1 5

*/