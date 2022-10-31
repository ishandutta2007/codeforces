# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 5e5+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int n, r[xn], l[xn];
ll a[xn], ans, dp[xn][2], b[xn];



int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	stack <int> st;
	
	for (int i = 0; i < n; i ++){
		while (st.size() && a[st.top()] > a[i]) st.pop();
		if (st.size()) l[i] = st.top();
		else l[i] = -1;
		st.push(i);
	}
	while (st.size()) st.pop();
	
	for (int i = n - 1; i >= 0; i --){
		while (st.size() && a[st.top()] > a[i]) st.pop();
		if (st.size()) r[i] = st.top();
		else r[i] = -1;
		st.push(i);
	}
	
	
	for (ll i = 0; i < n; i++){
		if (l[i] != -1) dp[i][0] = ((i - l[i]) * a[i]) + dp[l[i]][0];
		else dp[i][0] = (i + 1) * a[i];
	}
	for (ll i = n - 1; i >= 0; i--){
		if (r[i] != -1) dp[i][1] = (r[i] - i) * a[i] + dp[r[i]][1]; 
		else dp[i][1] = (n - i) * a[i];
	}
	
	ll ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, dp[i][0] + dp[i][1] - a[i]);
	
	
	for (int i = 0; i < n; i++){
		if (dp[i][0] + dp[i][1] - a[i] != ans) continue;
		b[i] = a[i];
		ll last = a[i];
		for (int j = i + 1; j < n; j++){
			last = min(last, a[j]);
			b[j] = last;
		}
		last = a[i];
		for (int j = i - 1; j >= 0; j--){
			last = min(last, a[j]);
			b[j] = last;
		}
		
		for (int j = 0; j < n; j++) cout << b[j] << sep;
		cout << endl;
		return 0;
	}
	
	
	return 0;
}