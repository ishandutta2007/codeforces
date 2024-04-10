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
#define N 5005
#define INF 101111111111111
using namespace std;
pll a[N];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n, m;
		cin >> n >> m;
		ll sum = 0;
		for(ll i =0;i<n;i++) {cin >> a[i].x;sum+=a[i].x;a[i].y = i;}
		if(m < n || n == 2){
			cout << -1 << endl;
		}else{
			ll res = sum*2;
			ll need = m-n;
			sort(a, a+n);
			res += need*(a[0].x+a[1].x);
			cout << res << endl;
			for(ll i = 0;i<n;i++) cout << a[i].y+1 << " " << a[(i+1)%n].y+1 << endl;
			for(ll i = 0;i<need;i++) cout << a[0].y+1 << " " << a[1].y+1 << endl;
		}
	}
}