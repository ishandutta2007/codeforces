#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 300010, MAX=15000000;

int d, n, x, y, m;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>d>>m;
	while (m--){
		cin>>x>>y;
		if ((x+y<d) || (n-x+y<n-d) || (x+n-y<n-d) || (x+y>(2*n-d))){
			cout<<"NO"<<endl;
			continue ;
		}
		
		cout<<"YES"<<endl;
	}
	return 0;
}