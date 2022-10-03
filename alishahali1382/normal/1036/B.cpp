#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 500 * 1000 + 10;

ll q, n, m, k, ans;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>q;
	for (; q; q--){
		cin>>n>>m>>k;
		if (m<n) swap(n, m);
		if (k<m){
			cout<<-1<<endl;
			continue ;
		}
		if (n==m){
			if ((k-n)%2) cout<<k-2<<endl;
			else cout<<k<<endl;
			continue ;
		}
		m-=n;
		k-=n;
		ans=n;
		if (m%2){
			if (!(k%2)) ans+=k-1;
			else ans+=k-1;
		}
		else{
			if (k%2) ans+=k-2;
			else ans+=k;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}