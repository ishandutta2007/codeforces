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
ll a[N];
map<string, ll> cc;
int main(){
	FAST;
	ll n, m;
	cin >> n >> m;
	for(ll i =0;i<n;i++) cin >> a[i];
	for(ll i =0;i<m;i++){
		string s;
		cin >> s;
		cc[s]++;
	}
	vector<ll> vec;
	for(auto i : cc) if(i.y > 0) vec.pb(i.y);
	sort(itr(vec), greater<ll>());
	sort(a, a+n);
	ll rmn = 0;
	for(ll i = 0;i<vec.size();i++){
		rmn += vec[i]*a[i];
	}
	sort(a, a+n, greater<ll>());
	ll rmx = 0;
	for(ll i = 0;i<vec.size();i++){
		rmx += vec[i]*a[i];
	}
	cout << rmn << " " << rmx << endl;
}