#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN=(ll)4000 * 1000 * 1000;

ll n, x;
ll ans;

map<int, ll> mp;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>x;
		for (ll j=1; j<MAXN; j*=2){
			ans+=mp[j-x];
		}
		mp[x]++;
	}
	cout<<ans<<endl;
		
	return 0;
}