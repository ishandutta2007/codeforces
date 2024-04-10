#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
bool check1(ll a, ll b){
	ll l = 0, r = a/2;
	while(r-l > 1){
		ll m  = (l+r)>>1;
		if(m+(a-2*m)*2 == b){
			l = m, r = m;
		}else if(m+(a-2*m)*2 > b){
			l = m;
		}else r = m;
	}
	ll res = -1;
	for(ll m = l;m<=r;m++) if(m+(a-2*m)*2 == b) {res = m; break;}
	return !(res == -1);
}
bool check2(ll a, ll b){
	return check1(a-1, b-2);
}
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll a, b;
		cin >> a >> b;
		if((a%3 == 0 && b%3 == 0 && check1(a, b)) || (a%3 == 1 && b%3 == 2 && check1(a, b)) || (a%3 == 2 && b%3 == 1 && check1(a, b))) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}