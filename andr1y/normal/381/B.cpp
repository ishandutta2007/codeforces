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
#define N 1000005
#define INF 101111111111111
using namespace std;
ll cnt[5005];
int main(){
	FAST;
	ll n;
	cin >> n;
	for(ll a, i = 0;i<n;i++){
		cin >> a;
		cnt[a]++;
	}
	ll maxc = -1;
	vector<ll> l, r;
	for(ll i = 5000;i>0;i--){
		if(cnt[i] > 0 && maxc == -1){
			maxc = i;
		}else if(cnt[i] == 1) l.pb(i);
		else if(cnt[i] >= 2) {l.pb(i);r.pb(i);}
	}
	cout << l.size() + r.size() + 1 << endl;
	sort(itr(l));
	for(auto i : l) cout << i << " ";
	cout << maxc << " ";
	for(auto i : r) cout << i << " ";
	cout << endl;
}