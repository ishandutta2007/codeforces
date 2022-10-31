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
int main(){
	FAST;
	ll n;
	cin >> n;
	string e, s;
	getline(cin, e);
	getline(cin, s);
	ll s1 = 0, s2 = 0, q1 = 0, q2 = 0;
	for(ll i =0;i<n;i++){
		if(s[i] == '?'){
			if(i < n/2) q1++;
			else q2++;
		}else{
			if(i < n/2) s1 += s[i]-'0';
			else s2 += s[i]-'0';
		}
	}
	ll fone = (q1+q2)>>1;
	bool cmw = false;
	for(ll i = 0;i<=min(q1, fone);i++){
		if(fone-i > q2) continue;
		ll m1s1 = s1;
		ll m1s2 = s2+(fone-i)*9;
		ll m2s1 = s1+i*9;
		ll m2s2 = s2;
		ll m1d = m1s1 - m1s2;
		ll m2d = m2s1 - m2s2;

		if(m1d < 0){
			m1d = abs(m1d);
			ll poss = (q1-i)*9;
			if(poss < m1d) cmw = 1;
		}else{
			ll poss = (q2-fone+i)*9;
			if(poss < m1d) cmw = 1;
		}

		if(m2d < 0){
			m2d = abs(m2d);
			ll poss = (q1-i)*9;
			if(poss < m2d) cmw = 1;
		}else{
			ll poss = (q2-fone+i)*9;
			if(poss < m2d) cmw = 1;
		}
	}
	if(cmw) cout << "Monocarp" << endl;
	else cout << "Bicarp" << endl;
}