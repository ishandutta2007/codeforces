# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const ll MD = md * 100;
const int xn = 2e5 + 10;
const int xm = 4e6 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 

 
int n;
ld A[xn], k;
vector <ld> B;

bool check(ll x){
	ld t = ld(x);
	ld ans = 0;
	ans += B[2];
	ans += t * B[1];
	ans += t * (t + 1) * B[0] / 2;
	return (ans >= k);
}
 
 
 
int main(){
	fast_io;
	
	cin >> n >> k;
	for (int i = 0; i < n; i ++) cin >> A[i];
	bool fl1 = false;
	for (int i = 0; i < n; i ++){
		if (!A[i] && !fl1) continue;
		fl1 = true;
		B.push_back(A[i]);
	}
	
	if (B.size() == 2){
		cout << ll(k - B[1] + B[0] - 1) / ll(B[0]) << endl;
		return 0;
	}
	if (B.size() == 3){
		ll L = -1, R = 2e9, Mid;
		while (R - L > 1){
			Mid = (L + R) / 2;
			if (check(Mid)) R = Mid;
			else L = Mid;
		}
		cout << R << endl;
		return 0;
	}
	ll cnt = 0;
	while (true){
		for (int i = 1; i < B.size(); i ++){
			if (B[i] >= k){
				cout << cnt << endl;
				return 0;
			}
			B[i] += B[i - 1];
		}
		cnt ++;
	}
	
	return 0;
}