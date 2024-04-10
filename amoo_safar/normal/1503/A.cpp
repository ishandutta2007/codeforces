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

bool Val(str X){
	int sm = 0;
	for(auto c : X){
		if(c == '(') sm ++;
		else sm --;
		if(sm < 0) return false;
	}

	return sm == 0;
}

int Main(){
	int n;
	cin >> n;
	str s;
	cin >> s;
	int c0 = 0;
	int c1 = 0;
	for(auto c : s) c0 += (c == '0');
	for(auto c : s) c1 += (c == '1');
	if((c0 % 2 == 1) || (c1 % 2 == 1)) return cout << "NO\n", 0;
	str A="", B="";
	int x0 = 0, x1 = 0;
	for(auto c : s){
		if(c == '1'){
			x1 ++;
			if(x1 <= c1 / 2) A += '(', B += '(';
			else A += ')', B += ')';
		} else {
			x0 ++;
			if(x0 % 2 == 0) A += '(', B += ')';
			else A += ')', B += '(';
		}
	}
	if(Val(A) && Val(B)){
		cout << "YES\n" << A << '\n' << B << '\n';
	} else cout << "NO\n";
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}
/*
5 1
1 2
2 3
3 4
1 5

*/