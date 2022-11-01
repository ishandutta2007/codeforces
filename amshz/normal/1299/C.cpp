# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e6 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;


int n;
ll a[xn];
vector <ld> ans;
stack <pii> st;


bool CMP(pii a, pii b){
	return a.F * b.S < b.F * a.S;
}



int main(){
	fast_io;
	
	cout << fixed << setprecision(12);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	for (int i = 1; i <= n; i ++){
		pii x = {a[i], 1LL};
		while (st.size() && CMP(x, st.top())){
			x.F += st.top().F;
			x.S += st.top().S;
			st.pop();
		}
		st.push(x);
	}
	
	while (st.size()){
		ld x = ld(st.top().F) / ld(st.top().S);
		for (int i = 0; i < st.top().S; i ++) ans.push_back(x);
		st.pop();
	}
	
	reverse(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); i ++) cout << ans[i] << endl;
	cout << endl;
	
	
	return 0;
}