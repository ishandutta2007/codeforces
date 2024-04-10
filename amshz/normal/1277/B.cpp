# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
 
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}
 
const int xn = 2e5+10;
const int xk = 10;
 
ll a[xn];
set <ll> st;
 
int main(){
	fast_io;
	int qq;
	cin>>qq;
	while (qq--){
		int n;
		cin>>n;
		int ans = 0;
		st.clear();
		for (int i=0; i<n; i++) cin>>a[i], st.insert(a[i]);
		while (st.size()){
			auto it = st.end();
			--it;
			ll nn = *it;
			if (nn%2 == 1){
				st.erase(it);
				continue;
			}
			st.erase(it);
			st.insert(nn/2);
			ans++;
		}
		cout << ans << endl;
	}
}