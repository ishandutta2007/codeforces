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
#define N 100005
#define INF 101111111111111
using namespace std;
ll p[N], r[N];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		stack<ll> free;
		bool ka = 1;
		for(ll i =1;i<=n;i++){
			ll a;
			cin >> a;
			p[i] = a;
			if(i == 1){
				r[1] = a;
				for(ll j = 1;j<a;j++) free.push(j);
			}else{
				if(p[i] == p[i-1]){
					if(free.size() > 0){
						r[i] = free.top();
						free.pop();
					}else{
						ka = 0;

					}
				}else{
					r[i] = p[i];
					for(ll j = p[i-1]+1;j<p[i];j++) free.push(j);
				}
			}
		}
		if(ka){
			for(ll i =1;i<=n;i++) cout << r[i] << " ";
				cout << endl;
		}else{
			cout << -1 << endl;
		}
	}
}