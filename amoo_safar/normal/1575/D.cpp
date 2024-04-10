// vaziat meshki-ghermeze !
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
const int N = 1e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int match(str A, str B){
	set<char> s;
	for(int i = 0; i < A.size(); i++){
		if(A[i] == 'X') s.insert(B[i]);
		else {
			if(A[i] != B[i] && A[i] != '_')
				return 0;
		}
	}
	return s.size() < 2;
}
int Solve(str Y){
	int L = (Y[0] != '0');
	str la = "";
	la += Y[Y.size() - 2];
	la += Y[Y.size() - 1];
	int R = match(la, "25") + match(la, "75") + match(la, "50") + match(la, "00");
	for(int i = 0; i + 2 < Y.size(); i++){
		if(Y[i] == '_') L *= (9 + (i == 0 ? 0 : 1));
	}
	return L * R;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	cin >> s;
	if(s.size() == 1)
		return cout << (s == "X" || s == "_" || s == "0") << '\n', 0;
	if(s.size() == 2){
		cout << match(s, "25") + match(s, "75") + match(s, "50") << '\n';
		return 0;
	}
	int ans = 0;
	int fl = 0;
	for(int c = '0'; c <= '9'; c++){
		str t = s;
		for(auto &x : t) if(x == 'X') x = c, fl = 1;
		ans += Solve(t);
	}
	if(fl) cout << ans << '\n';
	else cout << ans / 10 << '\n';
	return 0;
}