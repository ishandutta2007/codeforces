#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
void outn(char a, ll c){
	while(c--) cout << a;
	cout << endl;
}
int main(){
	FAST;
	ll a, b, n;
	outn('a', 300);
	cin >> a;
	if(a == 0) exit(0);
	a = 300-a;
	outn('b', 300);
	cin >> b;
	if(b == 0) exit(0);
	b = 300-b;
	string res = "";
	n = a+b;
	ll okb = 0;
	if(a == 0) {outn('b', b);exit(0);}
	if(b == 0) {outn('a', a);exit(0);}
	for(ll i = 0;i<n;i++){
		cout << res << "b";
		outn('a', n-i-1);
		ll val;
		cin >> val;
		if(val == 0) exit(0);
		if(b-val-okb == 1){
			okb++;
			res += "b";
		}else{
			res += "a";
		}
	}
	/*if(d1 < d2){
		n = d2;
		res += "a";
	}else{
		res += "b";
	}
	for(ll i = 1;i<n;i++){
		cout << res << "a" << endl;
		ll xv;
		cin >> xv;
		if(xv == 0) exit(0);
		if(xv == n-i) res += "b";
		else res += "a";
	}*/
}